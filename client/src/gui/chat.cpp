#include "chat.h"
#include "ui_chat.h"
#include <QLabel>
#include <QListWidgetItem>
#include <string>
Chat::Chat(QWidget *parent, Client *client) :
    QWidget(),
    ui(new Ui::Chat)
{
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
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
    std::string message = ui->input_msg->text().toStdString();
    client->Send(message);
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
            client->Send("#");
            event->accept();
    }
}

