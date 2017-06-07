/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_adminLogin
{
public:
    QLabel *label;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *adminLogin)
    {
        if (adminLogin->objectName().isEmpty())
            adminLogin->setObjectName(QStringLiteral("adminLogin"));
        adminLogin->resize(400, 300);
        label = new QLabel(adminLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 90, 141, 31));
        label->setAlignment(Qt::AlignCenter);
        plainTextEdit = new QPlainTextEdit(adminLogin);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(100, 130, 191, 41));

        retranslateUi(adminLogin);

        QMetaObject::connectSlotsByName(adminLogin);
    } // setupUi

    void retranslateUi(QDialog *adminLogin)
    {
        adminLogin->setWindowTitle(QApplication::translate("adminLogin", "Dialog", 0));
        label->setText(QApplication::translate("adminLogin", "Adminstrator Login", 0));
    } // retranslateUi

};

namespace Ui {
    class adminLogin: public Ui_adminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
