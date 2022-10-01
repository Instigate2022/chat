#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QCloseEvent>
#include "../engine/client.hpp"

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent, Client *client);
    bool pass_check(std::string pass, std::string check);
    bool login_check(std::string user_login);
    ~Registration();

private slots:
    void on_btn_reg_clicked();

    void on_btn_cancel_clicked();

    void on_input_name_textEdited(const QString &arg1);

    void on_input_conf_textEdited(const QString &arg1);

    void closeEvent(QCloseEvent *event);

private:
    QWidget *parent;
    Ui::Registration *ui;
    int serverSocket;
    Client *client;
};

#endif // REGISTRATION_H
