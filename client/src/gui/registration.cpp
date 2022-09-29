#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent, Client *client) :
    QWidget(),
    ui(new Ui::Registration)
{
    this->client = client;
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
    client->registration(ui->input_name->text().toStdString(), ui->input_pass->text().toStdString());
    this->close();
    parent->show();
}


void Registration::on_btn_cancel_clicked()
{
    this->close();
    parent->show();
}

