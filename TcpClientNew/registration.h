#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QMessageBox>
#include <QTcpSocket>
#include <QString>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent, QTcpSocket* socket);
    ~Registration();

private slots:
    void on_btn_reg_clicked();

    void on_btn_cancel_clicked();

private:
    QWidget *parent;
    Ui::Registration *ui;
    QTcpSocket* mSocket;
};

#endif // REGISTRATION_H
