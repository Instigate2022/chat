#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QTcpSocket>
#include <QTextStream>
#include <iostream>

#include "chat.h"
#include "registration.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_btn_login_clicked();

    void on_btn_reg_clicked();

private:
    Ui::Login *ui;
    QTcpSocket *mSocket;
    Chat *wind_chat;
    Registration *wind_reg;
};
#endif // LOGIN_H
