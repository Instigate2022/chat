#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent, Client *client) :
    QWidget(),
    ui(new Ui::Chat)
{
    this->client = client;
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
    client->Send(ui->input_msg->text().toStdString());
}

void Chat::on_btn_logOut_clicked()
{

}

