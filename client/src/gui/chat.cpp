#include "chat.h"
#include "ui_chat.h"
#include <QLabel>
#include <string>
#include "login.h"

QList<User*> users;

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
    users.push_back(new User("Server", new QListWidget(), true));
    connect(ui->input_msg, SIGNAL(returnPressed), this, SLOT(on_btn_send_clicked));
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
        client->disconnect();
        window->show();
        this->hide();
    } else {

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
            client->disconnect();
            event->accept();
    }
}

void Chat::set_list_message(std::string message)
{
    std::string name = message;
    std::cout << "Message = " << message << '\n';
    int erase_index = name.find_first_of(":");
    if (erase_index >= 0) {
        name.erase(name.find_first_of(":"));
    }
    std::cout << "Name: " << name << '\n';
    User *user = nullptr;
    for (int i = 0; i < users.size(); ++i) {
        if (users[i]->name == name) {
            user = users[i];
        }
    }
    if (user != nullptr) {
        if (user->chat == nullptr) {
            user->chat = new QListWidget();
        }
        user->chat->insertItem(0, message.c_str());
        return;
    }
    ui->list_chat->insertItem(0, message.c_str());
}

void Chat::set_users_list(std::string name)
{
    std::cout << "Add " << name << " In List Widget\n";
    User *new_user = new User(name, nullptr, true);
    users.push_back(new_user);
    QListWidgetItem *user_item = new QListWidgetItem(name.c_str());
    ui->list_users->addItem(user_item);
    QListWidgetItem *prev = ui->list_users->currentItem();
    ui->list_users->setCurrentItem(user_item);
    ui->list_users->setCurrentItem(prev);
    std::cout << "End set users list\n";
}

void Chat::on_list_users_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    std::cout << "\nChange chat called\n";
    std::string name = current->text().toStdString();
    User *user = nullptr;
    for (int i = 0; i < users.size(); ++i) {
        if (users[i]->name == name) {
            user = users[i];
        }
    }
    if (user == nullptr) return;
    if (user->chat == nullptr) {
        user->chat = new QListWidget();
    }
    std::cout << "User != nullptr\n";
    ui->list_chat->hide();
    std::cout << "Hide prev chat\n";
    ui->list_chat = user->chat;
    ui->verticalLayout->insertWidget(1, ui->list_chat);
    std::cout << "Show new chat\n";
    ui->list_chat->show();
}

