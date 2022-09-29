#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent, Client *client) :
    QWidget(),
    ui(new Ui::Registration)
{
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
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
    this->hide();
    parent->show();
}


void Registration::on_btn_cancel_clicked()
{
    this->hide();
    parent->show();
}

