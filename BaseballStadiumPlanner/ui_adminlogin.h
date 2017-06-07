/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminLogin
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_LoginText;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *LineEdit_Username;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *LineEdit_Password;

    void setupUi(QDialog *adminLogin)
    {
        if (adminLogin->objectName().isEmpty())
            adminLogin->setObjectName(QStringLiteral("adminLogin"));
        adminLogin->resize(291, 169);
        label = new QLabel(adminLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 141, 31));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(adminLogin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 120, 75, 23));
        label_LoginText = new QLabel(adminLogin);
        label_LoginText->setObjectName(QStringLiteral("label_LoginText"));
        label_LoginText->setGeometry(QRect(50, 150, 201, 20));
        layoutWidget = new QWidget(adminLogin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 50, 189, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        LineEdit_Username = new QLineEdit(layoutWidget);
        LineEdit_Username->setObjectName(QStringLiteral("LineEdit_Username"));

        horizontalLayout->addWidget(LineEdit_Username);

        layoutWidget1 = new QWidget(adminLogin);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 80, 187, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        LineEdit_Password = new QLineEdit(layoutWidget1);
        LineEdit_Password->setObjectName(QStringLiteral("LineEdit_Password"));
        LineEdit_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(LineEdit_Password);


        retranslateUi(adminLogin);

        QMetaObject::connectSlotsByName(adminLogin);
    } // setupUi

    void retranslateUi(QDialog *adminLogin)
    {
        adminLogin->setWindowTitle(QApplication::translate("adminLogin", "Dialog", 0));
        label->setText(QApplication::translate("adminLogin", "Adminstrator Login", 0));
        pushButton->setText(QApplication::translate("adminLogin", "Login", 0));
        label_LoginText->setText(QString());
        label_2->setText(QApplication::translate("adminLogin", "Username", 0));
        label_3->setText(QApplication::translate("adminLogin", "Password", 0));
    } // retranslateUi

};

namespace Ui {
    class adminLogin: public Ui_adminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
