#include "adminlogin.h"
#include "ui_adminlogin.h"

adminLogin::adminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminLogin)
{
    ui->setupUi(this);
}

adminLogin::~adminLogin()
{
    delete ui;
}

/****************************************************
void adminLogin::on_pushButton_clicked()
_____________________________________________________
check login info
*****************************************************/
void adminLogin::on_pushButton_clicked()
{
    QString username, password;

    username = ui->LineEdit_Username->text();
    password = ui->LineEdit_Password->text();

    if(username == "Annie" && password == "1130")
    {
        ui->label_LoginText->setText("Username and password is correct");

        this->hide();

        AdminFunc = new adminFuntion(this);
        AdminFunc->setModal(true);
        AdminFunc->show();

    }
    else
        ui->label_LoginText->setText("Username and password is not correct");


}
