#include "chat.h"
#include "ui_chat.h"
#include <QLabel>
#include <string>
#include "login.h"

QList<User*> users;

User* getUser(std::string name)
{
    for (int i = 0; i < users.size(); ++i) {
        if (users[i]->name == name) {
            return users[i];
        }
    }
    return nullptr;
}

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
    QListWidgetItem *server_item = new QListWidgetItem("Server");
    ui->list_users->addItem(server_item);
    users.push_back(new User("Server", new QListWidget(), server_item, true));
    connect(ui->input_msg, &QLineEdit::returnPressed, this, &Chat::on_btn_send_clicked);
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
        users.clear();
        Login *window = (Login* )login_wind;
        client->disconnect();
        window->show();
        this->hide();
    } else {

    }
}

void Chat::on_btn_file_clicked()
{
    QString filter = "All File (*.*) ;; Text File (*.txt) ;; XML File (*.xml) ;; PDF File (*.pdf)";
    client->file_link = QFileDialog::getOpenFileName(this,"Open the file",QDir::homePath(),filter).toStdString();
    std::cout << "File link: " << client->file_link << '\n';
    QMessageBox::StandardButton mesBtn = QMessageBox::question( this, "Chosen file",
                                    tr("Do you want to send this file?\n"),
                                    QMessageBox::No | QMessageBox::Yes,
                                    QMessageBox::Yes);
    if(mesBtn == QMessageBox::Yes) {
         std::string to_whom = ui->list_users->currentItem()->text().toStdString();
         client->sendFile(to_whom);
    }
    client->file_link = "";
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
        users.clear();
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
    User *user = getUser(name);
    if (user != nullptr) {
        if (user->chat == nullptr) {
            user->chat = new QListWidget();
        }
        user->chat->insertItem(0, message.c_str());
        if (ui->list_users->currentItem() != user->item) {
            user->item->setBackgroundColor(Qt::green);
        }
        return;
    }
    ui->list_chat->insertItem(0, message.c_str());
}

void Chat::set_users_list(std::string name)
{
    std::cout << "Add " << name << " In List Widget\n";
    User* user = getUser(name);
    if (user != nullptr) {
        user->item->setBackgroundColor(Qt::white);
        return;
    }
    QListWidgetItem *user_item = new QListWidgetItem(name.c_str());
    User *new_user = new User(name, nullptr, user_item, true);
    users.push_back(new_user);
    ui->list_users->addItem(user_item);
    QListWidgetItem *prev = ui->list_users->currentItem();
    ui->list_users->setCurrentItem(user_item);
    ui->list_users->setCurrentItem(prev);
    std::cout << "End set users list\n";
}

void Chat::on_list_users_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    std::string name = current->text().toStdString();
    User *user = getUser(name);
    if (user == nullptr) return;
    if (user->chat == nullptr) {
        user->chat = new QListWidget();
    }
    ui->list_chat->hide();
    ui->list_chat = user->chat;
    ui->verticalLayout->insertWidget(1, ui->list_chat);
    if (user->isOnline) {
        user->item->setBackgroundColor(Qt::white);
    } else {
        user->item->setBackgroundColor(Qt::red);
    }
    ui->list_chat->show();
}

void Chat::client_disconnected(std::string name)
{
    User* user = getUser(name);
    user->isOnline = false;
    user->item->setBackgroundColor(Qt::red);
}

