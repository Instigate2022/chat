#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QCloseEvent>
#include <QMessageBox>
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileDialog>
#include "../engine/client.hpp"


namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(void *parent, Client *client);
    ~Chat();
    void set_list_message(std::string msg);
    void set_users_list(std::string name);
    void client_disconnected(std::string name);

private slots:
    void on_btn_file_clicked();

    void on_btn_send_clicked();

    void on_btn_logOut_clicked();

    void closeEvent(QCloseEvent *event);

    void on_list_users_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::Chat *ui;
    void *login_wind;
    Client *client;
};

#endif // CHAT_H
