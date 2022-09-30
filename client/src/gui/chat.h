#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QCloseEvent>
#include <QMessageBox>
#include "../engine/client.hpp"

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent, Client *client);
    ~Chat();
    void set_list_message(std::string msg);
    void set_users_list(std::string name);

private slots:
    void on_btn_file_clicked();

    void on_btn_send_clicked();

    void on_btn_logOut_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::Chat *ui;
    Client *client;
};

#endif // CHAT_H
