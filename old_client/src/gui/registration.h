#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include "../engine/client.hpp"

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent, Client *client);
    ~Registration();

private slots:
    void on_btn_reg_clicked();

    void on_btn_cancel_clicked();

private:
    QWidget *parent;
    Ui::Registration *ui;
    int serverSocket;
    Client *client;
};

#endif // REGISTRATION_H
