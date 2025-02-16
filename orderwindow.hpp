#ifndef ORDERWINDOW_HPP
#define ORDERWINDOW_HPP

#include <QDebug>
#include <QWidget>
#include <QTimer>
#include <QPropertyAnimation>

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "cartmanager.hpp"
#include "item.hpp"

namespace Ui {
class OrderWindow;
}

class OrderWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OrderWindow(QWidget *parent = nullptr);
    ~OrderWindow();

private slots:
    void on_btn_add_hamburguer_clicked();

private:
    Ui::OrderWindow *ui;

    QTimer *cart_timer;
    QPropertyAnimation *cart_animation;
    CartManager cart_manager;

    void show_cart_widget();
    void update_cart();

    void send_to_server(const QJsonObject &message);

};

#endif // ORDERWINDOW_HPP
