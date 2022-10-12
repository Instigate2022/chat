#include "chat.h"
#include "ui_chat.h"
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
    connect(ui->input_msg, &QLineEdit::returnPressed, this, &Chat::on_btn_send_clicked);
    QListWidgetItem *server_item = new QListWidgetItem("Server");
    ui->list_users->addItem(server_item);
    users.push_back(new User("Server", new QListWidget(), server_item, true));
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
 if (isEdit == true) {
        ui->list_chat->currentItem()->setText(ui->input_msg->text() + " (edited)");
        isEdit = false;
        return;
    }

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
    ui->list_chat->scrollToBottom();
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
    ui->list_chat->scrollToBottom();
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
        user->item->setForeground(Qt::green);
        user->item->setIcon(QIcon(QPixmap("src/gui/icon.jpg")));
    }
    else {
		user->item->setIcon(QIcon(QPixmap("")));
    }
}

void Chat::set_users_list(std::string name)
{
    std::cout << "Add " << name << " In List Widget\n";
    User* user = getUser(name);
    if (user != nullptr) {
        user->item->setForeground(Qt::green);
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
    std::cout << "End set users list\n";
}

void Chat::on_list_users_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    Q_UNUSED(previous)
    std::string name = current->text().toStdString();
    ui->label_name->setText(current->text());
    User *user = getUser(name);
    if (user == nullptr) return;
    if (user->chat == nullptr) {
        user->chat = new QListWidget();
    }
    ui->list_chat->hide();
    user->item->setIcon(QIcon(QPixmap("")));
    ui->list_chat = user->chat;
    ui->verticalLayout->insertWidget(1, ui->list_chat);
    if (user->isOnline) {
        user->item->setForeground(Qt::green);
    } else {
        user->item->setForeground(Qt::red);
    }
    ui->list_chat->show();
}

void Chat::client_disconnected(std::string name)
{
    User* user = getUser(name);
    user->isOnline = false;
    user->item->setForeground(Qt::red);
}

void Chat::on_show_users_clicked()
{
    if (ui->list_users->isHidden()) {
        ui->list_users->show();
        ui->show_users->setText("<");
    } else {
        ui->show_users->setText(">");
        ui->list_users->hide();
    }
}

void Chat::contextMenuEvent ( QContextMenuEvent * event )
{
    QMenu* popMenu = new QMenu(this);
    QAction *deleteSeed = new QAction(tr("Delete"), this);
    QAction *clearSeeds = new QAction(tr("Clear"), this);
    QAction *editSeeds = new QAction(tr("Edit"), this);
    popMenu->addAction(deleteSeed);
    popMenu->addAction(clearSeeds);
    popMenu->addAction(editSeeds);
    connect(deleteSeed, SIGNAL(triggered()), this, SLOT(deleteSeedSlot()));
    connect(clearSeeds, SIGNAL(triggered()), this, SLOT(clearSeedsSlot()));
    connect(editSeeds, SIGNAL(triggered()), this, SLOT(editSeedsSlot()));
    popMenu->exec(QCursor::pos());
}
 
void Chat::deleteSeedSlot()
{
    int ch = QMessageBox::warning(NULL, "Warning",
                                  "Are you sure to delete seed ?",
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::No);
 
    if ( ch != QMessageBox::Yes )
        return;
 
    QListWidgetItem * item = ui->list_chat->currentItem();
    if( item == NULL )
        return;
    item->setText(" deleted message")  ;
}

void Chat::clearSeedsSlot()    
{                                                                                                                                                                                             
    int ch = QMessageBox::warning(NULL, "Warning",                                                                                                                                            
                                  "Are you sure to clear seeds ?",
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::No);

    if ( ch != QMessageBox::Yes )
        return;

    QListWidgetItem * item = ui->list_chat->currentItem();
    if( item == NULL )
        return;

    ui->list_chat->clear();
}

void Chat::editSeedsSlot()
{
    isEdit = true;
    QListWidgetItem *item = ui->list_chat->currentItem();
    if (item == NULL)
        return;
    ui->input_msg->setText(item->text());
}
