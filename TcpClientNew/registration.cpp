#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QWidget(),
    ui(new Ui::Registration)
{
    this->parent = parent;
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_btn_reg_clicked()
{
    this->close();
    parent->show();
}


void Registration::on_btn_cancel_clicked()
{
    this->close();
    parent->show();
}

