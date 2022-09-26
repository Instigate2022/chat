/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_welcom;
    QHBoxLayout *horizontalLayout;
    QLineEdit *input_login;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *input_pass;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_login;
    QLabel *label;
    QPushButton *btn_reg;
    QLabel *label_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(743, 549);
        Login->setMinimumSize(QSize(743, 549));
        Login->setMaximumSize(QSize(743, 549));
        Login->setContextMenuPolicy(Qt::PreventContextMenu);
        Login->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/bg-01.jpg);"));
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        label_welcom = new QLabel(Login);
        label_welcom->setObjectName(QString::fromUtf8("label_welcom"));
        label_welcom->setMinimumSize(QSize(0, 0));
        label_welcom->setMaximumSize(QSize(1000, 250));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_welcom->setFont(font);
        label_welcom->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_welcom);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(100, -1, 100, -1);
        input_login = new QLineEdit(Login);
        input_login->setObjectName(QString::fromUtf8("input_login"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_login->sizePolicy().hasHeightForWidth());
        input_login->setSizePolicy(sizePolicy);
        input_login->setMaximumSize(QSize(16777215, 30));
        input_login->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"border:0.5px solid grey;\n"
"background:white;"));

        horizontalLayout->addWidget(input_login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(100, -1, 100, -1);
        input_pass = new QLineEdit(Login);
        input_pass->setObjectName(QString::fromUtf8("input_pass"));
        input_pass->setMaximumSize(QSize(16777215, 30));
        input_pass->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"border:0.5px solid grey;\n"
"background:white;"));
        input_pass->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(input_pass);


        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(100, -1, 100, -1);
        btn_login = new QPushButton(Login);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
        btn_login->setSizePolicy(sizePolicy1);
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

        verticalLayout_3->addWidget(btn_login);

        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(1000, 20));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        btn_reg = new QPushButton(Login);
        btn_reg->setObjectName(QString::fromUtf8("btn_reg"));
        sizePolicy1.setHeightForWidth(btn_reg->sizePolicy().hasHeightForWidth());
        btn_reg->setSizePolicy(sizePolicy1);
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

        verticalLayout_3->addWidget(btn_reg);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777213, 70));

        verticalLayout_2->addWidget(label_2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        label_welcom->setText(QCoreApplication::translate("Login", "Welcome", nullptr));
        input_login->setText(QString());
        input_login->setPlaceholderText(QCoreApplication::translate("Login", "Login", nullptr));
        input_pass->setPlaceholderText(QCoreApplication::translate("Login", "Password", nullptr));
        label_3->setText(QString());
        btn_login->setText(QCoreApplication::translate("Login", "Login", nullptr));
        label->setText(QCoreApplication::translate("Login", "or", nullptr));
        btn_reg->setText(QCoreApplication::translate("Login", "Registration", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
