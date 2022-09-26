#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    mSocket->connectToHost("127.0.0.1", 1242);
}

Login::~Login()
{
    delete ui;
}


void Login::on_btn_login_clicked()
{
   wind_chat = new Chat(this);
   wind_chat->show();
   this->close();
}


void Login::on_btn_reg_clicked()
{
    wind_reg = new Registration(this, mSocket);
    wind_reg->show();
    this->close();
}

