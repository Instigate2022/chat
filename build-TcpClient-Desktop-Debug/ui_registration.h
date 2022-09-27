/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_welcom;
    QVBoxLayout *verticalLayout;
    QLineEdit *input_name;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *input_pass;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *input_conf;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_reg;
    QPushButton *btn_cancel;
    QLabel *label;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QStringLiteral("Registration"));
        Registration->resize(743, 549);
        Registration->setMinimumSize(QSize(743, 549));
        Registration->setMaximumSize(QSize(743, 549));
        verticalLayout_2 = new QVBoxLayout(Registration);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_welcom = new QLabel(Registration);
        label_welcom->setObjectName(QStringLiteral("label_welcom"));
        label_welcom->setMinimumSize(QSize(100, 100));
        label_welcom->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_welcom->setFont(font);
        label_welcom->setLayoutDirection(Qt::LeftToRight);
        label_welcom->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_welcom);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        input_name = new QLineEdit(Registration);
        input_name->setObjectName(QStringLiteral("input_name"));
        input_name->setMinimumSize(QSize(0, 30));
        input_name->setStyleSheet(QLatin1String("  border-radius: 5px;\n"
"border:0.5px solid grey;"));

        verticalLayout->addWidget(input_name);

        label_3 = new QLabel(Registration);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        label_3->setMaximumSize(QSize(16777215, 15));
        label_3->setScaledContents(false);

        verticalLayout->addWidget(label_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        input_pass = new QLineEdit(Registration);
        input_pass->setObjectName(QStringLiteral("input_pass"));
        input_pass->setMinimumSize(QSize(0, 30));
        input_pass->setStyleSheet(QLatin1String("  border-radius: 5px;\n"
"border:0.5px solid grey;"));
        input_pass->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(input_pass);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        input_conf = new QLineEdit(Registration);
        input_conf->setObjectName(QStringLiteral("input_conf"));
        input_conf->setMinimumSize(QSize(0, 30));
        input_conf->setStyleSheet(QLatin1String("  border-radius: 5px;\n"
"border:0.5px solid grey;"));
        input_conf->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(input_conf);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_2 = new QLabel(Registration);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 20));
        label_2->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btn_reg = new QPushButton(Registration);
        btn_reg->setObjectName(QStringLiteral("btn_reg"));
        btn_reg->setMinimumSize(QSize(430, 20));
        btn_reg->setMaximumSize(QSize(300, 30));
        btn_reg->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_4->addWidget(btn_reg);

        btn_cancel = new QPushButton(Registration);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setMinimumSize(QSize(90, 20));
        btn_cancel->setMaximumSize(QSize(250, 30));
        btn_cancel->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_4->addWidget(btn_cancel);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label = new QLabel(Registration);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 70));
        label->setMaximumSize(QSize(16777215, 70));

        verticalLayout_2->addWidget(label);


        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "Form", Q_NULLPTR));
        label_welcom->setText(QApplication::translate("Registration", "Registration", Q_NULLPTR));
        input_name->setPlaceholderText(QApplication::translate("Registration", "Name", Q_NULLPTR));
        label_3->setText(QString());
        input_pass->setPlaceholderText(QApplication::translate("Registration", "Password", Q_NULLPTR));
        input_conf->setPlaceholderText(QApplication::translate("Registration", "Confirm", Q_NULLPTR));
        label_2->setText(QString());
        btn_reg->setText(QApplication::translate("Registration", "Registration", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("Registration", "Cancel", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
