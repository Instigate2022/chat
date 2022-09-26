/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
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
    QListView *list_users;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
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
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(809, 518);
        horizontalLayout_3 = new QHBoxLayout(Chat);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        list_users = new QListView(Chat);
        list_users->setObjectName(QStringLiteral("list_users"));
        list_users->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(list_users);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_name = new QLabel(Chat);
        label_name->setObjectName(QStringLiteral("label_name"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_name->setFont(font);

        horizontalLayout_2->addWidget(label_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_logOut = new QPushButton(Chat);
        btn_logOut->setObjectName(QStringLiteral("btn_logOut"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        btn_logOut->setFont(font1);

        horizontalLayout_2->addWidget(btn_logOut);


        verticalLayout->addLayout(horizontalLayout_2);

        list_chat = new QListWidget(Chat);
        list_chat->setObjectName(QStringLiteral("list_chat"));

        verticalLayout->addWidget(list_chat);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        input_msg = new QLineEdit(Chat);
        input_msg->setObjectName(QStringLiteral("input_msg"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_msg->sizePolicy().hasHeightForWidth());
        input_msg->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(input_msg);

        btn_file = new QPushButton(Chat);
        btn_file->setObjectName(QStringLiteral("btn_file"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_file->sizePolicy().hasHeightForWidth());
        btn_file->setSizePolicy(sizePolicy1);
        btn_file->setFont(font1);

        horizontalLayout->addWidget(btn_file);

        btn_send = new QPushButton(Chat);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        sizePolicy1.setHeightForWidth(btn_send->sizePolicy().hasHeightForWidth());
        btn_send->setSizePolicy(sizePolicy1);
        btn_send->setFont(font1);

        horizontalLayout->addWidget(btn_send);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", Q_NULLPTR));
        label_name->setText(QApplication::translate("Chat", "Name", Q_NULLPTR));
        btn_logOut->setText(QApplication::translate("Chat", "Log Out", Q_NULLPTR));
        btn_file->setText(QApplication::translate("Chat", "File", Q_NULLPTR));
        btn_send->setText(QApplication::translate("Chat", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
