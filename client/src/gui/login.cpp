#include "login.h"
#include "ui_login.h"
#include <thread>

User::User(std::string name, QListWidget *chat, bool isOnline)
{
    this->name = name;
    this->chat = chat;
    this->isOnline = isOnline;
}

Login::Login(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::Login)
{
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
    client = new Client();
    ui->setupUi(this);
    if (!client->connect("127.0.0.1", 1234)) {
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

int spaces = 0;

void Login::on_btn_reg_clicked()
{
    wind_reg = new Registration(this, client);
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - wind_reg->width()) / 2;
    int y = (screenGeometry.height() - wind_reg->height()) / 2;
    wind_reg->move(x, y);
    wind_reg->show();
    this->hide();
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

