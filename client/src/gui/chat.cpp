#include "chat.h"
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
    QWidget()
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);
    QLabel *myLabel = new QLabel(this);
    int w = screenGeometry.width();
    int h = screenGeometry.height()*2;
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg").scaled(w,h, Qt::KeepAspectRatio));
    myLabel->show();
    login_wind = parent;
    setup(this);
    this->client = client;
    connect(input_msg, &QLineEdit::returnPressed, this, &Chat::on_btn_send_clicked);
    QListWidgetItem *server_item = new QListWidgetItem("Server");
    list_users->addItem(server_item);
    users.push_back(new User("Server", new QListWidget(), server_item, true));
}

Chat::~Chat()
{
}

void Chat::setup(QWidget *Chat)
{
    if (Chat->objectName().isEmpty())
        Chat->setObjectName(QString::fromUtf8("Chat"));
    Chat->resize(809, 518);
    horizontalLayout_3 = new QHBoxLayout(Chat);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    list_users = new QListWidget(Chat);
    list_users->setObjectName(QString::fromUtf8("list_users"));
    list_users->setMaximumSize(QSize(200, 16777215));

    horizontalLayout_3->addWidget(list_users);

    show_users = new QPushButton(Chat);
    show_users->setObjectName(QString::fromUtf8("show_users"));
    show_users->setEnabled(true);
    show_users->setMinimumSize(QSize(30, 30));
    show_users->setMaximumSize(QSize(30, 30));
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    font.setWeight(75);
    show_users->setFont(font);
    show_users->setStyleSheet(QString::fromUtf8(""));

    horizontalLayout_3->addWidget(show_users);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer_2);

    label_name = new QLabel(Chat);
    label_name->setObjectName(QString::fromUtf8("label_name"));
    QFont font1;
    font1.setPointSize(20);
    font1.setBold(true);
    font1.setWeight(75);
    label_name->setFont(font1);

    horizontalLayout_2->addWidget(label_name);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer);

    btn_logOut = new QPushButton(Chat);
    btn_logOut->setObjectName(QString::fromUtf8("btn_logOut"));
    QFont font2;
    font2.setPointSize(12);
    font2.setBold(true);
    font2.setWeight(75);
    btn_logOut->setFont(font2);

    horizontalLayout_2->addWidget(btn_logOut);


    verticalLayout->addLayout(horizontalLayout_2);

    list_chat = new QListWidget(Chat);
    list_chat->setObjectName(QString::fromUtf8("list_chat"));

    verticalLayout->addWidget(list_chat);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    input_msg = new QLineEdit(Chat);
    input_msg->setObjectName(QString::fromUtf8("input_msg"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(input_msg->sizePolicy().hasHeightForWidth());
    input_msg->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(input_msg);

    btn_file = new QPushButton(Chat);
    btn_file->setObjectName(QString::fromUtf8("btn_file"));
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(btn_file->sizePolicy().hasHeightForWidth());
    btn_file->setSizePolicy(sizePolicy1);
    btn_file->setFont(font2);

    horizontalLayout->addWidget(btn_file);

    btn_send = new QPushButton(Chat);
    btn_send->setObjectName(QString::fromUtf8("btn_send"));
    sizePolicy1.setHeightForWidth(btn_send->sizePolicy().hasHeightForWidth());
    btn_send->setSizePolicy(sizePolicy1);
    btn_send->setFont(font2);

    horizontalLayout->addWidget(btn_send);


    verticalLayout->addLayout(horizontalLayout);


    horizontalLayout_3->addLayout(verticalLayout);

    show_users->raise();
    list_users->raise();

    retranslate(Chat);

    QMetaObject::connectSlotsByName(Chat);
} // setup

void Chat::retranslate(QWidget *Chat)
{
    Chat->setWindowTitle(QApplication::translate("Chat", "Chat", nullptr));
    show_users->setText(QApplication::translate("Chat", "<", nullptr));
    label_name->setText(QApplication::translate("Chat", "Name", nullptr));
    btn_logOut->setText(QApplication::translate("Chat", "Log Out", nullptr));
    btn_file->setText(QApplication::translate("Chat", "File", nullptr));
    btn_send->setText(QApplication::translate("Chat", "Send", nullptr));
} // retranslate

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
    client->file_link = QFileDialog::getOpenFileName(this,"Open the file",QDir::homePath(),filter).toStdString();
    std::cout << "File link: " << client->file_link << '\n';
    QMessageBox::StandardButton mesBtn = QMessageBox::question( this, "Chosen file",
                                    tr("Do you want to send this file?\n"),
                                    QMessageBox::No | QMessageBox::Yes,
                                    QMessageBox::Yes);
    if(mesBtn == QMessageBox::Yes) {
         std::string to_whom = list_users->currentItem()->text().toStdString();
         client->sendFile(to_whom);
    }
    client->file_link = "";
}

void Chat::on_btn_send_clicked()
{
 if (isEdit == true) {
        list_chat->currentItem()->setText(input_msg->text() + " (edited)");
        isEdit = false;
        return;
    }

    std::string message = input_msg->text().toStdString();
    int size = list_users->count();
    if (size <= 0) {
        return;
    }
    std::string to_whom = list_users->currentItem()->text().toStdString();
    client->Send(message, to_whom);
    QListWidgetItem *item = new QListWidgetItem();
    item->setTextAlignment(Qt::AlignRight);
    item->setText(message.c_str());
    list_chat->addItem(item);
    input_msg->clear();
    list_chat->scrollToBottom();
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
    list_chat->scrollToBottom();
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
    if (list_users->currentItem() != user->item) {
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
    list_users->addItem(user_item);
    QListWidgetItem *prev = list_users->currentItem();
    list_users->setCurrentItem(user_item);
    if (prev == nullptr) {
        return;
    }
    std::cout << "End set users list\n";
}

void Chat::on_list_users_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    Q_UNUSED(previous)
    std::string name = current->text().toStdString();
    label_name->setText(current->text());
    User *user = getUser(name);
    if (user == nullptr) return;
    if (user->chat == nullptr) {
        user->chat = new QListWidget();
    }
    list_chat->hide();
    user->item->setIcon(QIcon(QPixmap("")));
    list_chat = user->chat;
    verticalLayout->insertWidget(1, list_chat);
    if (user->isOnline) {
        user->item->setForeground(Qt::green);
    } else {
        user->item->setForeground(Qt::red);
    }
    list_chat->show();
}

void Chat::client_disconnected(std::string name)
{
    User* user = getUser(name);
    user->isOnline = false;
    user->item->setForeground(Qt::red);
}

void Chat::on_show_users_clicked()
{
    if (list_users->isHidden()) {
        list_users->show();
        show_users->setText("<");
    } else {
        show_users->setText(">");
        list_users->hide();
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

    QListWidgetItem * item = list_chat->currentItem();
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

    QListWidgetItem * item = list_chat->currentItem();
    if( item == NULL )
        return;

    list_chat->clear();
}

void Chat::editSeedsSlot()
{
    isEdit = true;
    QListWidgetItem *item = list_chat->currentItem();
    if (item == NULL)
        return;
    input_msg->setText(item->text());
}
