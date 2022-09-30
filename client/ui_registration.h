/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
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

    void setupUi(QWidget *Registration)
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


        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "Form", 0, QApplication::UnicodeUTF8));
        label_welcom->setText(QApplication::translate("Registration", "Registration", 0, QApplication::UnicodeUTF8));
        input_name->setPlaceholderText(QApplication::translate("Registration", "Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        input_pass->setPlaceholderText(QApplication::translate("Registration", "Password", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        input_conf->setPlaceholderText(QApplication::translate("Registration", "Confirm", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_2->setText(QString());
        btn_reg->setText(QApplication::translate("Registration", "Registration", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("Registration", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
