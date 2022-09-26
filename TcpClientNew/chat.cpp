#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QWidget(),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_btn_file_clicked()
{

}

void Chat::on_btn_send_clicked()
{

}

void Chat::on_btn_logOut_clicked()
{

}

