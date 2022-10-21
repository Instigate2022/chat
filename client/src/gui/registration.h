#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QStyle>
#include <QMessageBox>
#include <QString>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <cstring>
#include "../engine/client.hpp"
#include <QLabel>
#include <QRect>
#include <QtCore/QVariant>
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>


class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent, Client *client, bool isConnected);
    bool pass_check(std::string pass, std::string check);
    bool login_check(std::string user_login);
    void setup(QWidget *Registration);
    void retranslate(QWidget *Registration);
    ~Registration();

    QVBoxLayout *verticalLayout_2;
    QLabel *label_welcom;
    QVBoxLayout *verticalLayout;
    QLineEdit *input_name;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *input_pass;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *input_conf;
    QLabel *label_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_reg;
    QPushButton *btn_cancel;
    QLabel *label;

private slots:
    void on_btn_reg_clicked();

    void on_btn_cancel_clicked();

    void on_input_name_textEdited(const QString &arg1);

    void on_input_conf_textEdited(const QString &arg1);

    void closeEvent(QCloseEvent *event);

    void on_input_pass_textEdited(const QString &arg1);

    void analysis_pass(bool& uppercase,bool& lowercase,bool& number,bool& symbols, std::string pass);

private:
    QWidget *parent;
    int serverSocket;
    Client *client;
    bool isConnected;
};

#endif // REGISTRATION_H
