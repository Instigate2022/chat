#include "registration.h"

Registration::Registration(QWidget *parent, Client *client, bool isConnected) :
    QWidget()
{
    this->isConnected = isConnected;
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);
    QLabel *myLabel = new QLabel(this);
    myLabel->setPixmap(QPixmap("src/gui/bg-01.jpg"));
    myLabel->show();
    this->client = client;
    this->parent = parent;
    setup(this);
    connect(input_name,  &QLineEdit::returnPressed, this, &Registration::on_btn_reg_clicked);
    connect(input_pass,  &QLineEdit::returnPressed, this, &Registration::on_btn_reg_clicked);
    connect(input_conf,  &QLineEdit::returnPressed, this, &Registration::on_btn_reg_clicked);
    if(!isConnected) {
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
    }
}

void Registration::setup(QWidget *Registration)
{
    if (Registration->objectName().isEmpty())
        Registration->setObjectName(QString::fromUtf8("Registration"));
    Registration->resize(743, 549);
    Registration->setMinimumSize(QSize(743, 549));
    Registration->setMaximumSize(QSize(743, 549));
    verticalLayout_2 = new QVBoxLayout(Registration);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label_welcom = new QLabel(Registration);
    label_welcom->setObjectName(QString::fromUtf8("label_welcom"));
    label_welcom->setMinimumSize(QSize(100, 100));
    label_welcom->setMaximumSize(QSize(16777215, 100));
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    font.setWeight(75);
    label_welcom->setFont(font);
    label_welcom->setLayoutDirection(Qt::LeftToRight);
    label_welcom->setAlignment(Qt::AlignCenter);

    verticalLayout_2->addWidget(label_welcom);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(2);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    input_name = new QLineEdit(Registration);
    input_name->setObjectName(QString::fromUtf8("input_name"));
    input_name->setMinimumSize(QSize(0, 30));
    input_name->setStyleSheet(QString::fromUtf8("  border-radius: 5px;\n"
"border:0.5px solid grey;"));

    verticalLayout->addWidget(input_name);

    label_3 = new QLabel(Registration);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setEnabled(true);
    label_3->setMaximumSize(QSize(16777215, 15));
    label_3->setScaledContents(false);

    verticalLayout->addWidget(label_3);


    verticalLayout_2->addLayout(verticalLayout);

    verticalLayout_5 = new QVBoxLayout();
    verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
    input_pass = new QLineEdit(Registration);
    input_pass->setObjectName(QString::fromUtf8("input_pass"));
    input_pass->setMinimumSize(QSize(0, 30));
    input_pass->setStyleSheet(QString::fromUtf8("  border-radius: 5px;\n"
"border:0.5px solid grey;"));
    input_pass->setEchoMode(QLineEdit::Password);

    verticalLayout_5->addWidget(input_pass);

    label_4 = new QLabel(Registration);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setMaximumSize(QSize(16777215, 15));

    verticalLayout_5->addWidget(label_4);


    verticalLayout_2->addLayout(verticalLayout_5);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    input_conf = new QLineEdit(Registration);
    input_conf->setObjectName(QString::fromUtf8("input_conf"));
    input_conf->setMinimumSize(QSize(0, 30));
    input_conf->setStyleSheet(QString::fromUtf8("  border-radius: 5px;\n"
"border:0.5px solid grey;"));
    input_conf->setEchoMode(QLineEdit::Password);

    verticalLayout_3->addWidget(input_conf);

    label_5 = new QLabel(Registration);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setMaximumSize(QSize(16777215, 15));

    verticalLayout_3->addWidget(label_5);


    verticalLayout_2->addLayout(verticalLayout_3);

    label_2 = new QLabel(Registration);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setMinimumSize(QSize(0, 20));
    label_2->setMaximumSize(QSize(16777215, 20));

    verticalLayout_2->addWidget(label_2);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    btn_reg = new QPushButton(Registration);
    btn_reg->setObjectName(QString::fromUtf8("btn_reg"));
    btn_reg->setMinimumSize(QSize(430, 20));
    btn_reg->setMaximumSize(QSize(300, 30));
    btn_reg->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-color: #d84315; \n"
"  color: white;\n"
"  border: none;\n"
"  border-radius: 8px;\n"
"  font-size: 16px;\n"
" text-align: center;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: #424242;\n"
"\n"
"\n"
"}"));

    horizontalLayout->addWidget(btn_reg);

    btn_cancel = new QPushButton(Registration);
    btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
    btn_cancel->setMinimumSize(QSize(90, 20));
    btn_cancel->setMaximumSize(QSize(250, 30));
    btn_cancel->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-color: #263238; \n"
"  color: white;\n"
"  border: none;\n"
"  border-radius: 8px;\n"
"  font-size: 16px;\n"
" text-align: center;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: #424242;\n"
"\n"
"\n"
"}"));

    horizontalLayout->addWidget(btn_cancel);
    verticalLayout_2->addLayout(horizontalLayout);

    label = new QLabel(Registration);
    label->setObjectName(QString::fromUtf8("label"));
    label->setMinimumSize(QSize(0, 70));
    label->setMaximumSize(QSize(16777215, 70));

    verticalLayout_2->addWidget(label);

    retranslate(Registration);

    QMetaObject::connectSlotsByName(Registration);
} // setup

void Registration::retranslate(QWidget *Registration)
{
    Registration->setWindowTitle(QApplication::translate("Registration", "Registration", nullptr));
    label_welcom->setText(QApplication::translate("Registration", "Registration", nullptr));
    input_name->setPlaceholderText(QApplication::translate("Registration", "Name", nullptr));
    label_3->setText(QString());
    input_pass->setPlaceholderText(QApplication::translate("Registration", "Password", nullptr));
    label_4->setText(QString());
    input_conf->setPlaceholderText(QApplication::translate("Registration", "Confirm", nullptr));
    label_5->setText(QString());
    label_2->setText(QString());
    btn_reg->setText(QApplication::translate("Registration", "Registration", nullptr));
    btn_cancel->setText(QApplication::translate("Registration", "Cancel", nullptr));
    label->setText(QString());
} // retranslate

bool Registration::login_check(std::string user_login)
{
    if(!((user_login[0] >= 'a' && user_login[0] <= 'z') ||
       (user_login[0] >= 'A' && user_login[0] <= 'Z'))) {
        label_3->setText("First letter should be a-z or A-Z");
        label_3->setStyleSheet("QLabel { color : red; }");
        return false;
    }

    label_3->setText("");

    for (unsigned int i = 1; i < user_login.size(); ++i) {
        if(!((user_login[i] == '.' || user_login[i] == '_' || user_login[i] == '-') ||
          (user_login[i] >= 'a' && user_login[i] <= 'z') ||
          (user_login[i] >= 'A' && user_login[i] <= 'Z'))) {
           label_3->setText("Need to use uppercase, lowercase or symbols(-, _, .)");
           label_3->setStyleSheet("QLabel { color : red; }");
           return false;
        }
    }
    return true;
}

bool Registration::pass_check(std::string pass, std::string check)
{
    label_4->clear();
    label_5->clear();
    bool uppercase = false;
    bool lowercase = false;
    bool number = false;
    bool symbols = false;

    analysis_pass(uppercase,lowercase,number,symbols,pass);

    if(pass.size() < 4) {
        label_4->setText("Password must contain at least 4 characters.");
        label_4->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    else if(uppercase == 0 || lowercase == 0 || number == 0) {
        label_4->setText("Password must contain at least one lowercase, uppercase and number.");
        label_4->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    else if(!symbols) {
        label_4->setText("Password only can contain these !@#$%^&*_-+=|/;.,: symbols");
        label_4->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    if(pass != check) {
        label_5->setText("Password confirmation failed. Fields do not match.");
        label_5->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    return true;
}

Registration::~Registration()
{
}

void Registration::analysis_pass(bool& uppercase,bool& lowercase,bool& number,bool& symbols, std::string pass)
{
    std::cout << "\n\n ANALYS START\n";
    std::string symbols_list = "!@#$%^&*_-+=|/;.,:";
    for(size_t i = 0; i < pass.size(); i++) {
        if(pass[i] >='A' && pass[i] <= 'Z') {
            std::cout << "ANALISE 1\n";
                uppercase = true;
        }
        else if (pass[i] >= 'a' && pass[i] <= 'z') {
            std::cout << "ANALISE 2\n";
                lowercase = true;
        }
        else if (pass[i] >= '0' && pass[i] <= '9') {
            std::cout << "ANALISE 3\n";
                number = true;
        }
        else {
            std::cout << "ANALISE 4\n";
            int index = symbols_list.find(pass[i]);
            std::cout << "Index: " << index << '\n';
            if (index >= 0) {
                std::cout << "TRUE\n";
                symbols = true;
            }
            else {
                std::cout << "False\n";
                symbols = false;
                return;
            }
        }
    }
}

void Registration::on_btn_reg_clicked()
{
    if(!isConnected) {
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
        return;
    }
    std::string user_login = input_name->text().toStdString();
    for(auto&i : user_login)
    {
        i = tolower(i);
    }
    std::string pass = input_pass->text().toStdString();
    std::string check = input_conf->text().toStdString();
    if(!(login_check(user_login))) {
        return;
    }
    if(!(pass_check(pass, check))) {
        return;
    }
    if(client->registration(user_login, input_pass->text().toStdString())){

        input_name->clear();
        input_pass->clear();
        input_conf->clear();
        this->hide();
        parent->show();
    } else {
        label_3->setText("User with this login is exist");
        label_3->setStyleSheet("QLabel { color : red; }");
    }
}

void Registration::on_btn_cancel_clicked()
{
    this->hide();
    parent->show();
}

void Registration::on_input_name_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    label_3->setText("");
    std::string user_login = input_name->text().toStdString();
    login_check(user_login);
}

void Registration::on_input_conf_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    label_4->setText("");
    label_5->setText("");
    pass_check(input_pass->text().toStdString(), input_conf->text().toStdString());
}

void Registration::on_input_pass_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    label_4->setText("");
    label_5->setText("");
    pass_check(input_pass->text().toStdString(), input_conf->text().toStdString());
}

void Registration::closeEvent(QCloseEvent *event)
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
