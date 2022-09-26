#ifndef CHAT_H
#define CHAT_H

#include <QWidget>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

private slots:
    void on_btn_file_clicked();

    void on_btn_send_clicked();

    void on_btn_logOut_clicked();

private:
    Ui::Chat *ui;
};

#endif // CHAT_H
