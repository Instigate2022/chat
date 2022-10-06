#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent, Client *client) :
    QWidget(),
    ui(new Ui::Registration)
{
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
}

bool Registration::login_check(std::string user_login)
{
    if(!((user_login[0] >= 65 && user_login[0] <= 90) ||
       (user_login[0] >= 97 && user_login[0] <= 122))) {
        ui->label_3->setText("Smth is wrong, Login can not have spaces and first letter should be a-z or A-Z");
        ui->label_3->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    ui->label_3->setText("");

    for (unsigned int i = 0; i < user_login.size(); ++i) {
        if(user_login[i] == ' ') {
            QMessageBox::warning(this, "Incorrect Login Name!", "Login can not have spaces.");
            return false;
        }
    }
    return true;
}

bool Registration::pass_check(std::string pass, std::string check)
{
    int uppercase = 0;
    int lowercase = 0;
    int number = 0;
    unsigned int i;
    if(pass != check) {
        ui->label_5->setText("Password confirmation failed. Fields do not match.");
        ui->label_5->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    for(i = 0; i < pass.size(); i++) {
        if(pass[i] >=65 && pass[i] <= 90) {
            ++uppercase;
        }
        if (pass[i] >= 97 && pass[i] <= 122) {
            ++lowercase;
        }
        if (pass[i] >= 48 && pass[i] <= 57) {
            ++number;
        }
    }
    if(i < 4) {
        ui->label_4->setText("Password must contain at least 4 characters.");
        ui->label_4->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    if(uppercase == 0 || lowercase == 0 || number == 0) {
        ui->label_4->setText("Password must contain at least one lowercase, uppercase and number.");
        ui->label_4->setStyleSheet("QLabel { color : red; }");
        return false;
    }
    return true;
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_btn_reg_clicked()
{
    std::string user_login = ui->input_name->text().toStdString();
    std::string pass = ui->input_pass->text().toStdString();
    std::string check = ui->input_conf->text().toStdString();
    if(!(login_check(user_login))) {
        return;
    }
    if(!(pass_check(pass, check))) {
        return;
    }
    if(ui->input_pass->text() != ui->input_conf->text()) {
        ui->label_5->setText("Not Matching");
	    ui->label_5->setStyleSheet("QLabel { color : red; }");
        return;
    }
    if(client->registration(ui->input_name->text().toStdString(), ui->input_pass->text().toStdString())) {
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
    ui->label_3->setText("");
    std::string user_login = ui->input_name->text().toStdString();
       if(!(login_check(user_login))) {
           return;
       }
}

void Registration::on_input_conf_textEdited(const QString &arg1)
{
    ui->label_4->setText("");
    ui->label_5->setText("");
    if(!(pass_check(ui->input_pass->text().toStdString(), ui->input_conf->text().toStdString()))) {
        return;
    }
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
