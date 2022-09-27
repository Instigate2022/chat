/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(743, 549);
        Login->setMinimumSize(QSize(743, 549));
        Login->setMaximumSize(QSize(743, 549));
        Login->setContextMenuPolicy(Qt::PreventContextMenu);
        Login->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/bg-01.jpg);"));
        verticalLayoutWidget = new QWidget(Login);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 751, 551));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 370, 19, 19));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(1000, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_welcom = new QLabel(Login);
        label_welcom->setObjectName(QStringLiteral("label_welcom"));
        label_welcom->setGeometry(QRect(290, 90, 138, 32));
        label_welcom->setMinimumSize(QSize(0, 0));
        label_welcom->setMaximumSize(QSize(1000, 250));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_welcom->setFont(font1);
        label_welcom->setAlignment(Qt::AlignCenter);
        input_pass = new QLineEdit(Login);
        input_pass->setObjectName(QStringLiteral("input_pass"));
        input_pass->setGeometry(QRect(110, 260, 551, 30));
        input_pass->setMaximumSize(QSize(16777215, 30));
        input_pass->setStyleSheet(QLatin1String("border-radius: 5px;\n"
"border:0.5px solid grey;\n"
"background:white;"));
        input_pass->setEchoMode(QLineEdit::Password);
        btn_reg = new QPushButton(Login);
        btn_reg->setObjectName(QStringLiteral("btn_reg"));
        btn_reg->setGeometry(QRect(210, 400, 300, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_reg->sizePolicy().hasHeightForWidth());
        btn_reg->setSizePolicy(sizePolicy);
        btn_reg->setMinimumSize(QSize(0, 0));
        btn_reg->setMaximumSize(QSize(1000, 30));
        btn_reg->setStyleSheet(QLatin1String("QPushButton{\n"
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
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(210, 330, 300, 30));
        sizePolicy.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
        btn_login->setSizePolicy(sizePolicy);
        btn_login->setMinimumSize(QSize(0, 0));
        btn_login->setMaximumSize(QSize(1000, 30));
        btn_login->setStyleSheet(QLatin1String("QPushButton{\n"
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
        input_login->setObjectName(QStringLiteral("input_login"));
        input_login->setGeometry(QRect(110, 200, 551, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(input_login->sizePolicy().hasHeightForWidth());
        input_login->setSizePolicy(sizePolicy1);
        input_login->setMaximumSize(QSize(16777215, 30));
        input_login->setStyleSheet(QLatin1String("border-radius: 5px;\n"
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
        Login->setWindowTitle(QApplication::translate("Login", "Login", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "or", Q_NULLPTR));
        label_welcom->setText(QApplication::translate("Login", "Welcome", Q_NULLPTR));
        input_pass->setPlaceholderText(QApplication::translate("Login", "Password", Q_NULLPTR));
        btn_reg->setText(QApplication::translate("Login", "Registration", Q_NULLPTR));
        btn_login->setText(QApplication::translate("Login", "Login", Q_NULLPTR));
        input_login->setText(QString());
        input_login->setPlaceholderText(QApplication::translate("Login", "Login", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
