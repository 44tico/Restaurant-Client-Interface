#include "orderwindow.hpp"
#include "ui_orderwindow.h"

OrderWindow::OrderWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::OrderWindow) {
    ui->setupUi(this);

    QPixmap hamburguer {"/home/ticodanick/Downloads/hamburguer.png"};
    ui->lbl_hambuguer->setPixmap(hamburguer.scaled(80, 80, Qt::KeepAspectRatio));

    ui->cart->hide();

    cart_timer = new QTimer(this);
    connect(cart_timer, &QTimer::timeout, this, [this]() {
        QPropertyAnimation *animation_out = new QPropertyAnimation(ui->cart, "pos");
        animation_out->setDuration(300);
        animation_out->setStartValue(ui->cart->pos());
        animation_out->setEndValue(QPoint(ui->cart->x(), height()));
        animation_out->start(QAbstractAnimation::DeleteWhenStopped);

        connect(animation_out, &QPropertyAnimation::finished, this, [this](){
            ui->cart->hide();
        });
    });

    cart_animation = new QPropertyAnimation(ui->cart, "pos");
    cart_animation->setDuration(300);

    ui->spin_hamburguer_quantity->setValue(1);
}

OrderWindow::~OrderWindow() {
    delete ui;
}

void OrderWindow::on_btn_add_hamburguer_clicked() {
    Item hamburguer {ui->lbl_hambuguer->text(), 19.99, ui->spin_hamburguer_quantity->value()};
    cart_manager.add_item(hamburguer);

    update_cart();
    show_cart_widget();

    ui->spin_hamburguer_quantity->setValue(1);

    QJsonObject message{
        {"type", "ADD_ITEM"},
        {"data", QJsonObject{
                     {"table", 1},
                     {"item", QJsonObject{
                                  {"name", hamburguer.name},
                                  {"price", hamburguer.price},
                                  {"quantity", hamburguer.quantity}
                              }}
                 }}
    };

    send_to_server(message);
}

void OrderWindow::show_cart_widget() {
    ui->cart->move(ui->cart->x(), height() - ui->cart->height());
    ui->cart->show();

    cart_animation->setStartValue(QPoint(ui->cart->x(), height()));
    cart_animation->setEndValue(QPoint(ui->cart->x(), height() - ui->cart->height()));
    cart_animation->start();

    cart_timer->start(3000);
}

void OrderWindow::update_cart() {
    ui->list_cart->clear();

    for(const Item &item : cart_manager){
        QString item_text {QString("%1 x %2 - R$ %3")
            .arg(item.quantity)
                .arg(item.name)
                .arg(item.price * item.quantity)};

        ui->list_cart->addItem(item_text);
    }
}

void OrderWindow::send_to_server(const QJsonObject &message) {
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 12345);

    if(socket->waitForConnected()){
        qDebug() << "Conectado ao servidor com sucesso!";
        QByteArray data {QJsonDocument(message).toJson(QJsonDocument::Compact) + '\n'};
        socket->write(data);
        socket->waitForBytesWritten();
        socket->disconnectFromHost();
    } else{
        qDebug() << "Erro ao conectar ao servidor." << socket->errorString();
    }

    socket->deleteLater();
}
