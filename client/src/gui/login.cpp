#include "login.h"

User::User(std::string name, QListWidget *chat, QListWidgetItem* item, bool isOnline)
{
    this->name = name;
    this->chat = chat;
    this->item = item;
    this->isOnline = isOnline;
}

Login::Login(Client* client, bool isConnected)
    : QWidget()
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
    setup(this);
    this->client = client;
    this->show();
    err_log->setStyleSheet("QLabel { color : red; }");
    err_pass->setStyleSheet("QLabel { color : red; }");
    connect(input_login,  &QLineEdit::returnPressed, this, &Login::on_btn_login_clicked);
    connect(input_pass,  &QLineEdit::returnPressed, this, &Login::on_btn_login_clicked);
    if(!isConnected) {
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
    }
}

Login::~Login()
{
}

void Login::setup(QWidget *Login)
{
    if (Login->objectName().isEmpty())
        Login->setObjectName(QString::fromUtf8("Login"));
    Login->resize(743, 549);
    Login->setMinimumSize(QSize(743, 549));
    Login->setMaximumSize(QSize(743, 549));
    Login->setContextMenuPolicy(Qt::PreventContextMenu);
    Login->setStyleSheet(QString::fromUtf8(""));
    verticalLayoutWidget = new QWidget(Login);
    verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
    verticalLayoutWidget->setGeometry(QRect(0, 0, 751, 551));
    verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout_2->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(Login);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(350, 370, 19, 19));
    label->setMinimumSize(QSize(0, 0));
    label->setMaximumSize(QSize(1000, 20));
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    label_welcom = new QLabel(Login);
    label_welcom->setObjectName(QString::fromUtf8("label_welcom"));
    label_welcom->setGeometry(QRect(280, 90, 138, 32));
    label_welcom->setMinimumSize(QSize(0, 0));
    label_welcom->setMaximumSize(QSize(1000, 250));
    QFont font1;
    font1.setPointSize(20);
    font1.setBold(true);
    font1.setWeight(75);
    label_welcom->setFont(font1);
    label_welcom->setAlignment(Qt::AlignCenter);
    input_pass = new QLineEdit(Login);
    input_pass->setObjectName(QString::fromUtf8("input_pass"));
    input_pass->setGeometry(QRect(110, 260, 551, 30));
    input_pass->setMaximumSize(QSize(16777215, 30));
    input_pass->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"border:0.5px solid grey;\n"
"background:white;"));
    input_pass->setEchoMode(QLineEdit::Password);
    btn_reg = new QPushButton(Login);
    btn_reg->setObjectName(QString::fromUtf8("btn_reg"));
    btn_reg->setGeometry(QRect(210, 400, 300, 30));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(btn_reg->sizePolicy().hasHeightForWidth());
    btn_reg->setSizePolicy(sizePolicy);
    btn_reg->setMinimumSize(QSize(0, 0));
    btn_reg->setMaximumSize(QSize(1000, 30));
    btn_reg->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-color: #212121; \n"
"  color: white;\n"
"  border: none;\n"
"  border-radius: 10px;\n"
"  font-size: 16px;\n"
" text-align: center;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: #424242;\n"
"\n"
"\n"
"}"));
    btn_login = new QPushButton(Login);
    btn_login->setObjectName(QString::fromUtf8("btn_login"));
    btn_login->setGeometry(QRect(210, 330, 300, 30));
    sizePolicy.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
    btn_login->setSizePolicy(sizePolicy);
    btn_login->setMinimumSize(QSize(0, 0));
    btn_login->setMaximumSize(QSize(1000, 30));
    btn_login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-color: #d84315; \n"
"  color: white;\n"
"  border: none;\n"
"  border-radius: 10px;\n"
"  font-size: 16px;\n"
" text-align: center;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: #424242;\n"
"\n"
"\n"
"}"));
    input_login = new QLineEdit(Login);
    input_login->setObjectName(QString::fromUtf8("input_login"));
    input_login->setGeometry(QRect(110, 200, 551, 30));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(input_login->sizePolicy().hasHeightForWidth());
    input_login->setSizePolicy(sizePolicy1);
    input_login->setMaximumSize(QSize(16777215, 30));
    input_login->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"border:0.5px solid grey;\n"
"background:white;"));
    err_log = new QLabel(Login);
    err_log->setObjectName(QString::fromUtf8("err_log"));
    err_log->setGeometry(QRect(110, 230, 551, 21));
    err_pass = new QLabel(Login);
    err_pass->setObjectName(QString::fromUtf8("err_pass"));
    err_pass->setGeometry(QRect(110, 290, 551, 16));
    QWidget::setTabOrder(input_login, input_pass);
    QWidget::setTabOrder(input_pass, btn_login);
    QWidget::setTabOrder(btn_login, btn_reg);

    retranslate(Login);

    QMetaObject::connectSlotsByName(Login);
} // setup

void Login::retranslate(QWidget *Login)
{
    Login->setWindowTitle(QApplication::translate("Login", "Login", nullptr));
    label->setText(QApplication::translate("Login", "or", nullptr));
    label_welcom->setText(QApplication::translate("Login", "Welcome", nullptr));
    input_pass->setPlaceholderText(QApplication::translate("Login", "Password", nullptr));
    btn_reg->setText(QApplication::translate("Login", "Registration", nullptr));
    btn_login->setText(QApplication::translate("Login", "Login", nullptr));
    input_login->setText(QString());
    input_login->setPlaceholderText(QApplication::translate("Login", "Login", nullptr));
    err_log->setText(QString());
    err_pass->setText(QString());
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
    err_pass->clear();
    err_log->clear();
    std::cout << "Start Login\n";
    std::string user_login = input_login->text().toStdString();
    for(auto&i : user_login)
    {
        i = tolower(i);
    }
    std::string reply = client->login(user_login, input_pass->text().toStdString());

    std::cout << "Reply: " << reply << '\n';
    if (reply == "Ok") {
        input_login->clear();
        input_pass->clear();
        run_chat();
        return;
    }
    if (reply == "Cancel"){
        err_log->setText("This user is not registered. Can register");
        return;
    }
    if (reply == "Wrong") {
        err_pass->setText("Wrong Password. Please check your password");
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
