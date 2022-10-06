#include "chat.h"
#include "ui_chat.h"
#include <QLabel>
#include <string>
#include "login.h"
#include <QIcon>

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
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
    login_wind = parent;
    ui->setupUi(this);
    this->client = client;
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
        client->logOut();
        users.clear();
        Login *window = (Login*)login_wind;
        window->show();
        this->hide();
    } else {

    }
}

void Chat::on_btn_file_clicked()
{
    QString filter = "All File (*.*) ;; Text File (*.txt) ;; XML File (*.xml) ;; PDF File (*.pdf)";
    std::string file_link = QFileDialog::getOpenFileName(this,"Open the file",QDir::homePath(),filter).toStdString();
    QMessageBox::StandardButton mesBtn = QMessageBox::question( this, "Chosen file",
                                    tr("Do you want to send this file?\n"),
                                    QMessageBox::No | QMessageBox::Yes,
                                    QMessageBox::Yes);
    if(mesBtn == QMessageBox::Yes) {
         std::string to_whom = ui->list_users->currentItem()->text().toStdString();
         //client->sendFile(to_whom);
    }
    file_link = "";
}

void Chat::on_btn_send_clicked()
{
    std::string message = ui->input_msg->text().toStdString();
    int size = ui->list_users->count();
    if (size <= 0) {
        return;
    }
    std::string to_whom = ui->list_users->currentItem()->text().toStdString();
    client->Send(message, to_whom);
    QListWidgetItem *item = new QListWidgetItem();
    item->setTextAlignment(Qt::AlignRight);
    item->setText(message.c_str());
    ui->list_chat->addItem(item);
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
        //client->disconnect("{##}");
        event->accept();
    }
}

template<typename T> void print_vector(std::vector<T> list)
{
    for(int i = 0; i < list.size(); i++) {
        std::cout << i << " " << list[i] << '\n';
    }
}

void Chat::set_list_message(std::string by_user, std::string message)
{
    std::cout << "New Message By user: " << by_user << '\n';
    std::cout << "Message = " << message << '\n';
    User *user = getUser(by_user);
    if (user == nullptr) {
        return;
    }
    std::cout << "User Finded\n";
    if (user->chat == nullptr) {
        user->chat = new QListWidget();
    }
    user->chat->addItem(message.c_str());
    if (user->item == nullptr) {
        user->item = new QListWidgetItem(user->name.c_str());
    }
    if (ui->list_users->currentItem() != user->item) {
        user->item->setBackgroundColor(Qt::green);
        user->item->setIcon(QIcon(QPixmap("icon.png")));
    }
    return;
    if (ui->list_chat == nullptr) {
        std::cout << "Add list widget\n";
        ui->list_chat = new QListWidget();
    }
    ui->list_chat->insertItem(0, message.c_str());
    std::cout << "End insertItem\n";
}

void Chat::set_users_list(std::string name)
{
    std::cout << "Add " << name << " In List Widget\n";
    User* user = getUser(name);
    if (user != nullptr) {
        user->item->setBackgroundColor(Qt::white);
        user->isOnline = true;
        return;
    }
    QListWidgetItem *user_item = new QListWidgetItem(name.c_str());
    User *new_user = new User(name, nullptr, user_item, true);
    users.push_back(new_user);
    ui->list_users->addItem(user_item);
    QListWidgetItem *prev = ui->list_users->currentItem();
    ui->list_users->setCurrentItem(user_item);
    if (prev == nullptr) {
        return;
    }
    //ui->list_users->setCurrentItem(prev);
    std::cout << "End set users list\n";
}

void Chat::on_list_users_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    std::cout << "Current item changed\n";
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
    std::cout << "End Current Item changed\n";
}

void Chat::client_disconnected(std::string name)
{
    User* user = getUser(name);
    user->isOnline = false;
    user->item->setBackgroundColor(Qt::red);
}

