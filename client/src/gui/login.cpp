#include "login.h"
#include "ui_login.h"

User::User(std::string name, QListWidget *chat, QListWidgetItem* item, bool isOnline)
{
    this->name = name;
    this->chat = chat;
    this->item = item;
    this->isOnline = isOnline;
}

Login::Login(Client* client, bool isConnected)
    : QWidget()
      , ui(new Ui::Login)
{
    this->isConnected = isConnected;
    wind_reg = new Registration(this, client, isConnected);
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
    ui->setupUi(this);
    this->client = client;
    this->show();
    ui->err_log->setStyleSheet("QLabel { color : red; }");
    ui->err_pass->setStyleSheet("QLabel { color : red; }");
    connect(ui->input_login,  &QLineEdit::returnPressed, this, &Login::on_btn_login_clicked);
    connect(ui->input_pass,  &QLineEdit::returnPressed, this, &Login::on_btn_login_clicked);
    if(!isConnected) {
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
    }
}

Login::~Login()
{
    delete ui;
}

void Login::run_chat()
{
    wind_chat = new Chat(this, client);
    wind_chat->show();
    client->set_chat_window(wind_chat);
    this->hide();
    client->run();
}

void Login::on_btn_login_clicked()
{
    if(!isConnected) {
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
        return;
    }
    ui->err_pass->clear();
    ui->err_log->clear();
    std::cout << "Start Login\n";
    std::string reply = client->login(ui->input_login->text().toStdString(), ui->input_pass->text().toStdString());
    std::cout << "Reply: " << reply << '\n';
    if (reply == "Ok") {
        run_chat();
        return;
    }
    if (reply == "Cancel"){
        ui->err_log->setText("This user is not registered. Can register");
        return;
    }
    if (reply == "Wrong") {
        ui->err_pass->setText("Wrong Password. Please check your password");
        return;
    }
    if (reply == "error") {
        isConnected = false;
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
        return;
    }
	wind_chat = new Chat(this, client);
}


void Login::on_btn_reg_clicked()
{
    if(!isConnected) {
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
        return;
    }
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
        //client->disconnect("{##}");
        event->accept();
    }
}
