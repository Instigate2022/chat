#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent, QTcpSocket* mSocket) :
    QWidget(),
    ui(new Ui::Registration)
{
    this->mSocket = mSocket;
    this->parent = parent;
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_btn_reg_clicked()
{
    if(ui->input_pass->text() != ui->input_conf->text()) {
        QMessageBox::warning(this, "Registration failed!", "Password is not equal Confirm");
        return;
    }
    std::string message = ui->input_name->text().toStdString();
    message += " " + ui->input_pass->text().toStdString();
    QTextStream T(mSocket);
    T << message.c_str();
    mSocket->flush();

    this->close();
    parent->show();
}


void Registration::on_btn_cancel_clicked()
{
    this->close();
    parent->show();
}

