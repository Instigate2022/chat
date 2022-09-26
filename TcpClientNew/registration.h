#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_btn_reg_clicked();

    void on_btn_cancel_clicked();

private:
    QWidget *parent;
    Ui::Registration *ui;
};

#endif // REGISTRATION_H