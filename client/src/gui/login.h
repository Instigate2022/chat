#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QTextStream>
#include <iostream>
#include <QDesktopWidget>
#include <QListWidget>

#include "chat.h"
#include "registration.h"
#include "../engine/client.hpp"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

struct User
{
    User(std::string name, QListWidget *chat, bool isOnline);

    std::string name;
    QListWidget* chat = nullptr;
    bool isOnline;
};

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_btn_login_clicked();

    void on_btn_reg_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::Login *ui;
    Client *client;
    Chat *wind_chat;
    Registration *wind_reg;
};
#endif // LOGIN_H