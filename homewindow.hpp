#ifndef HOMEWINDOW_HPP
#define HOMEWINDOW_HPP

#include <QMainWindow>

#include "orderwindow.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class HomeWindow;
}
QT_END_NAMESPACE

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

private slots:
    void on_btn_start_clicked();

private:
    Ui::HomeWindow *ui;
};
#endif // HOMEWINDOW_HPP
