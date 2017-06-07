#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include "adminfuntion.h"

namespace Ui {
class adminLogin;
}

class adminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit adminLogin(QWidget *parent = 0);
    ~adminLogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::adminLogin *ui;
    adminFuntion* AdminFunc;


};

#endif // ADMINLOGIN_H
