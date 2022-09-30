#include "chat.h"
#include "ui_chat.h"
#include <QLabel>
#include <QListView>
#include <QListWidgetItem>
#include <string>
#include "login.h"

Chat::Chat(void *parent, Client *client) :
    QWidget(),
    ui(new Ui::Chat)
{
    login_wind = parent;
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
    ui->setupUi(this);
    client->set_chat_window(this);
    this->client = client;
    ui->list_users->addItem("Server");
//    connect(ui->input_msg, &QLineEdit::returnPressed, this, &Chat::on_btn_send_clicked);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_btn_logOut_clicked()
{
	QMessageBox::StandardButton mesBtn = QMessageBox::question( this, "Log-out window",
                                    tr("Are you sure want to log out?\n"),
                                    QMessageBox::No | QMessageBox::Yes,
                                    QMessageBox::Yes);
	
    if(mesBtn == QMessageBox::Yes) {
	    Login *window = (Login* )login_wind;
	    window->show();
	    this->hide();
    } else {
            client->Send("Log out", "Server");
    }
    


}
void Chat::on_btn_file_clicked()
{

}

void Chat::on_btn_send_clicked()
{
    std::string message = ui->input_msg->text().toStdString();
    std::string to_whom = ui->list_users->currentItem()->text().toStdString();
    client->Send(message, to_whom);
    QListWidgetItem *item = new QListWidgetItem();
    item->setTextAlignment(Qt::AlignRight);
    item->setText(message.c_str());
    ui->list_chat->insertItem(0,item);
    ui->input_msg->clear();
}

void Chat::closeEvent(QCloseEvent *event)
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

void Chat::set_list_message(std::string message)
{
    ui->list_chat->insertItem(0, message.c_str());
}

void Chat::set_users_list(std::string name)
{
    std::cout << "Add " << name << " In List Widget\n";
    ui->list_users->addItem(name.c_str());
}
