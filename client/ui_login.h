/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_welcom;
    QLineEdit *input_pass;
    QPushButton *btn_reg;
    QPushButton *btn_login;
    QLineEdit *input_login;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(743, 549);
        Login->setMinimumSize(QSize(743, 549));
        Login->setMaximumSize(QSize(743, 549));
        Login->setContextMenuPolicy(Qt::PreventContextMenu);
        Login->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/bg-01.jpg);"));
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
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_welcom = new QLabel(Login);
        label_welcom->setObjectName(QString::fromUtf8("label_welcom"));
        label_welcom->setGeometry(QRect(290, 90, 138, 32));
        label_welcom->setMinimumSize(QSize(0, 0));
        label_welcom->setMaximumSize(QSize(1000, 250));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
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
        QWidget::setTabOrder(input_login, input_pass);
        QWidget::setTabOrder(input_pass, btn_login);
        QWidget::setTabOrder(btn_login, btn_reg);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Login", "or", 0, QApplication::UnicodeUTF8));
        label_welcom->setText(QApplication::translate("Login", "Welcome", 0, QApplication::UnicodeUTF8));
        input_pass->setPlaceholderText(QApplication::translate("Login", "Password", 0, QApplication::UnicodeUTF8));
        btn_reg->setText(QApplication::translate("Login", "Registration", 0, QApplication::UnicodeUTF8));
        btn_login->setText(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
        input_login->setText(QString());
        input_login->setPlaceholderText(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
