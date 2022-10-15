#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent, Client *client, bool isConnected) :
    QWidget(),
    ui(new Ui::Registration)
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
    ui->setupUi(this);
    connect(ui->input_name,  &QLineEdit::returnPressed, this, &Registration::on_btn_reg_clicked);
    connect(ui->input_pass,  &QLineEdit::returnPressed, this, &Registration::on_btn_reg_clicked);
    connect(ui->input_conf,  &QLineEdit::returnPressed, this, &Registration::on_btn_reg_clicked);
    if(!isConnected) {
        QMessageBox::critical(this, "Connect Error", "Don`t connected");
    }
}

bool Registration::login_check(std::string user_login)
{
    if(!((user_login[0] >= 'a' && user_login[0] <= 'z') ||
       (user_login[0] >= 'A' && user_login[0] <= 'Z'))) {
        ui->label_3->setText("First letter should be a-z or A-Z");
        ui->label_3->setStyleSheet("QLabel { color : red; }");
        return false;
    }

    ui->label_3->setText("");

    for (unsigned int i = 1; i < user_login.size(); ++i) {
        if(!((user_login[i] == '.' || user_login[i] == '_' || user_login[i] == '-') ||
          (user_login[i] >= 'a' && user_login[i] <= 'z') ||
          (user_login[i] >= 'A' && user_login[i] <= 'Z'))) {
           ui->label_3->setText("Need to use uppercase, lowercase or symbols(-, _, .)");
           ui->label_3->setStyleSheet("QLabel { color : red; }");
           return false;
        }
    }
    return true;
}

bool Registration::pass_check(std::string pass, std::string check)
{
    ui->label_4->clear();
    ui->label_5->clear();
    bool uppercase = false;
    bool lowercase = false;
    bool number = false;
    bool symbols = false;

    analysis_pass(uppercase,lowercase,number,symbols,pass);

    if(pass.size() < 4) {
        ui->label_4->setText("Password must contain at least 4 characters.");
        ui->label_4->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    else if(uppercase == 0 || lowercase == 0 || number == 0) {
        ui->label_4->setText("Password must contain at least one lowercase, uppercase and number.");
        ui->label_4->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    else if(!symbols) {
        ui->label_4->setText("Password only can contain these !@#$%^&*_-+=|/;.,: symbols");
        ui->label_4->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    if(pass != check) {
        ui->label_5->setText("Password confirmation failed. Fields do not match.");
        ui->label_5->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    return true;
}

Registration::~Registration()
{
    delete ui;
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
    std::string user_login = ui->input_name->text().toStdString();
    std::string pass = ui->input_pass->text().toStdString();
    std::string check = ui->input_conf->text().toStdString();
    if(!(login_check(user_login))) {
        return;
    }
    if(!(pass_check(pass, check))) {
        return;
    }
    if(client->registration(ui->input_name->text().toStdString(), ui->input_pass->text().toStdString())){

        ui->input_name->clear();
        ui->input_pass->clear();
        ui->input_conf->clear();
        this->hide();
        parent->show();
    } else {
        ui->label_3->setText("User with this login is exist");
	    ui->label_3->setStyleSheet("QLabel { color : red; }");
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
    ui->label_3->setText("");
    std::string user_login = ui->input_name->text().toStdString();
    login_check(user_login);
}

void Registration::on_input_conf_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    ui->label_4->setText("");
    ui->label_5->setText("");
    pass_check(ui->input_pass->text().toStdString(), ui->input_conf->text().toStdString());
}

void Registration::on_input_pass_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    ui->label_4->setText("");
    ui->label_5->setText("");
    pass_check(ui->input_pass->text().toStdString(), ui->input_conf->text().toStdString());
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
