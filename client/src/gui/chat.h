#ifndef CHAT_H
#define CHAT_H

#include "../engine/client.hpp"
#include <string>
#include <QIcon>
#include <QMenu>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMetaType>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QItemSelection>
#include <QHBoxLayout>
#include <QtCore/QVariant>
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(void *parent, Client *client);
    ~Chat();
    void set_list_message(std::string by_user, std::string msg);
    void set_users_list(std::string name);
    void client_disconnected(std::string name);
    void setup(QWidget *Chat);
    void retranslate(QWidget *Chat);

    QHBoxLayout *horizontalLayout_3;
    QListWidget *list_users;
    QPushButton *show_users;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_logOut;
    QListWidget *list_chat;
    QHBoxLayout *horizontalLayout;
    QLineEdit *input_msg;
    QPushButton *btn_file;
    QPushButton *btn_send;

private slots:
    void contextMenuEvent ( QContextMenuEvent * event ) ;
    void closeEvent(QCloseEvent *event);
    void on_btn_file_clicked();
    void on_btn_send_clicked();
    void on_btn_logOut_clicked();
    void on_show_users_clicked();
    void deleteSeedSlot();
    void clearSeedsSlot();
    void editSeedsSlot();
    void on_list_users_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    void *login_wind;
    Client *client;
    bool isEdit = false;
};

#endif // CHAT_H
