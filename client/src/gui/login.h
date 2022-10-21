#ifndef LOGIN_H
#define LOGIN_H

#include "chat.h"
#include "registration.h"
#include "../engine/client.hpp"
#include <iostream>
#include <QWidget>
#include <QThread>
#include <QTextStream>
#include <QListWidget>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QtCore/QVariant>
#include <QLabel>
#include <QLineEdit>

struct User
{
    User(std::string name, QListWidget *chat, QListWidgetItem *item, bool isOnline);
    std::string name;
    QListWidget* chat = nullptr;
    QListWidgetItem *item = nullptr;
    bool isOnline;
};

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(Client *client, bool isConnected);
    ~Login();
    void setup(QWidget *Login);
    void retranslate(QWidget *Login);
    void run_chat();

    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_welcom;
    QLineEdit *input_pass;
    QPushButton *btn_reg;
    QPushButton *btn_login;
    QLineEdit *input_login;
    QLabel *err_log;
    QLabel *err_pass;

private slots:
    void on_btn_reg_clicked();
    void on_btn_login_clicked();
    void closeEvent(QCloseEvent *event);

private:
    Client *client;
    Chat *wind_chat;
    Registration *wind_reg;
    bool isConnected;
};
#endif // LOGIN_H
