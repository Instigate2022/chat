/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QHBoxLayout *horizontalLayout_3;
    QListWidget *list_users;
    QPushButton *show_users;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_logOut;
    QListWidget *list_chat;
    QHBoxLayout *horizontalLayout;
    QLineEdit *input_msg;
    QPushButton *btn_file;
    QPushButton *btn_send;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(809, 518);
        horizontalLayout_3 = new QHBoxLayout(Chat);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        list_users = new QListWidget(Chat);
        list_users->setObjectName(QString::fromUtf8("list_users"));
        list_users->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(list_users);

        show_users = new QPushButton(Chat);
        show_users->setObjectName(QString::fromUtf8("show_users"));
        show_users->setEnabled(true);
        show_users->setMinimumSize(QSize(30, 30));
        show_users->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        show_users->setFont(font);
        show_users->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(show_users);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_name = new QLabel(Chat);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_name->setFont(font1);

        horizontalLayout_2->addWidget(label_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_logOut = new QPushButton(Chat);
        btn_logOut->setObjectName(QString::fromUtf8("btn_logOut"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        btn_logOut->setFont(font2);

        horizontalLayout_2->addWidget(btn_logOut);


        verticalLayout->addLayout(horizontalLayout_2);

        list_chat = new QListWidget(Chat);
        list_chat->setObjectName(QString::fromUtf8("list_chat"));

        verticalLayout->addWidget(list_chat);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        input_msg = new QLineEdit(Chat);
        input_msg->setObjectName(QString::fromUtf8("input_msg"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_msg->sizePolicy().hasHeightForWidth());
        input_msg->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(input_msg);

        btn_file = new QPushButton(Chat);
        btn_file->setObjectName(QString::fromUtf8("btn_file"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_file->sizePolicy().hasHeightForWidth());
        btn_file->setSizePolicy(sizePolicy1);
        btn_file->setFont(font2);

        horizontalLayout->addWidget(btn_file);

        btn_send = new QPushButton(Chat);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        sizePolicy1.setHeightForWidth(btn_send->sizePolicy().hasHeightForWidth());
        btn_send->setSizePolicy(sizePolicy1);
        btn_send->setFont(font2);

        horizontalLayout->addWidget(btn_send);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        show_users->raise();
        list_users->raise();

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QCoreApplication::translate("Chat", "Chat", nullptr));
        show_users->setText(QCoreApplication::translate("Chat", "<", nullptr));
        label_name->setText(QCoreApplication::translate("Chat", "Name", nullptr));
        btn_logOut->setText(QCoreApplication::translate("Chat", "Log Out", nullptr));
        btn_file->setText(QCoreApplication::translate("Chat", "File", nullptr));
        btn_send->setText(QCoreApplication::translate("Chat", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
