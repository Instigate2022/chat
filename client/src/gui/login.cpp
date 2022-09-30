#include "login.h"
#include "ui_login.h"
#include <thread>

Login::Login(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::Login)
{
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
    client = new Client();
    ui->setupUi(this);
    if (!client->connect("127.0.0.1", 1235)) {
        QMessageBox::critical(this, "Connect Error", "Dont connected, try again");
        exit(0);
    }
}

Login::~Login()
{
    delete ui;
}


void Login::on_btn_login_clicked()
{
    std::cout << "Start Login\n";
    std::string message = "{?} ";
    message += ui->input_login->text().toStdString();
    message += " " + ui->input_pass->text().toStdString();
    std::cout << message << '\n';
    int spaces = 0;
    for (int i = 0; i < message.size(); i++) {
        if (message[i] == ' ') {
            spaces += 1;
        }
    }
    std::cout << "Spaces: " << spaces <<"\n";

    if(spaces > 2) {
        QMessageBox::warning(this, "Login failed!", "Login or Password are incorrect");
        return;
    }
    if (client->login(ui->input_login->text().toStdString(), ui->input_pass->text().toStdString())) {
        std::thread th1([&](){client->run();});
        th1.detach();
        wind_chat = new Chat(this, client);
        wind_chat->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Error", "Wrong Login or Password");
    }
}


void Login::on_btn_reg_clicked()
{
    wind_reg = new Registration(this, client);
    wind_reg->show();
    this->hide();
}

void Chat::on_btn_logOut_clicked()
{

}

void Login::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Close window",
                                                                tr("Do you want to abort this operation?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if(resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        client->Send("#", "Server");
        event->accept();
    }
}

