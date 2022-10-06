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
    if(!isConnected) {
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
        exit(1);
    }
    wind_reg = new Registration(this, client);
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
    ui->setupUi(this);
<<<<<<< HEAD
    this->client = client;
    this->show();
    ui->err_log->setStyleSheet("QLabel { color : red; }");
    ui->err_pass->setStyleSheet("QLabel { color : red; }");
=======
    connect(ui->input_login,  &QLineEdit::returnPressed, this, &Login::on_btn_login_clicked);
    connect(ui->input_pass,  &QLineEdit::returnPressed, this, &Login::on_btn_login_clicked);
>>>>>>> 0b3e56989e11cc62b91517360ef305d961e2a16a
}

Login::~Login()
{
    delete ui;
}

<<<<<<< HEAD
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
    ui->err_pass->clear();
    ui->err_log->clear();
=======
void Login::on_btn_login_clicked()
{
    if (!client->connect("127.0.0.1", 1233)) {
        QMessageBox::critical(this, "Connect Error", "Dont connected, try again");
    }
>>>>>>> 0b3e56989e11cc62b91517360ef305d961e2a16a
    std::cout << "Start Login\n";
    std::string reply = client->login(ui->input_login->text().toStdString(), ui->input_pass->text().toStdString());
    if (reply == "Ok") {
        run_chat();
        return;
    }
    if (reply == "Cancel"){
        ui->err_log->setText("This user is not registered. Can register");
        return;
    }
<<<<<<< HEAD
    if (reply == "Wrong") {
        ui->err_pass->setText("Wrong Password. Please check your password");
        return;
=======
    if (client->login(ui->input_login->text().toStdString(), ui->input_pass->text().toStdString())) {

	    ///todo move thread to run function
	std::thread th1([&](){client->run();});
        th1.detach();
	
	wind_chat = new Chat(this, client);
    	QRect screenGeometry = QApplication::desktop()->screenGeometry();
    	int x = (screenGeometry.width() - wind_chat->width()) / 2;
    	int y = (screenGeometry.height() - wind_chat->height()) / 2;
   	wind_chat->move(x, y);
        wind_chat->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Error", "Wrong Login or Password");
>>>>>>> 0b3e56989e11cc62b91517360ef305d961e2a16a
    }
}


void Login::on_btn_reg_clicked()
{
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

