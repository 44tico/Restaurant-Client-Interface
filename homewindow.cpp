#include "homewindow.hpp"
#include "./ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::HomeWindow){
    ui->setupUi(this);
}

HomeWindow::~HomeWindow() {
    delete ui;
}

void HomeWindow::on_btn_start_clicked(){
    OrderWindow *order_window = new OrderWindow();
    order_window->setAttribute(Qt::WA_DeleteOnClose);
    order_window->show();

    this->close();
}

