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
   std::string message = "{?} ";
   message += ui->input_login->text().toStdString();
   message += " " + ui->input_pass->text().toStdString();
   std::cout << message << '\n';

   int a = 0;
   for (int i = 0; i < message.size(); i++) {
       if (message[i] == ' ') {
           a += 1;
       }
   }
    std::cout << a <<"\n";

   if(a > 2) {
       QMessageBox::warning(this, "Login failed!", "Login or Password are incorrect");
       return;
   }

   QTextStream T(mSocket);
   T << message.c_str();
   mSocket->flush();


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

