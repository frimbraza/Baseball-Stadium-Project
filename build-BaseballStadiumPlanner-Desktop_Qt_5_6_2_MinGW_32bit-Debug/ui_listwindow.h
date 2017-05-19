/********************************************************************************
** Form generated from reading UI file 'listwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWINDOW_H
#define UI_LISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ListWindow
{
public:
    QPushButton *listAllStadiums;
    QPushButton *listAmLeagueStadiums;
    QPushButton *listNLStadiums;
    QPushButton *ListGrassStadiums;
    QPushButton *ListChronologicalStadium;
    QTextBrowser *listDisplayBox;

    void setupUi(QDialog *ListWindow)
    {
        if (ListWindow->objectName().isEmpty())
            ListWindow->setObjectName(QStringLiteral("ListWindow"));
        ListWindow->resize(899, 456);
        listAllStadiums = new QPushButton(ListWindow);
        listAllStadiums->setObjectName(QStringLiteral("listAllStadiums"));
        listAllStadiums->setGeometry(QRect(40, 30, 191, 31));
        listAmLeagueStadiums = new QPushButton(ListWindow);
        listAmLeagueStadiums->setObjectName(QStringLiteral("listAmLeagueStadiums"));
        listAmLeagueStadiums->setGeometry(QRect(40, 80, 191, 31));
        listNLStadiums = new QPushButton(ListWindow);
        listNLStadiums->setObjectName(QStringLiteral("listNLStadiums"));
        listNLStadiums->setGeometry(QRect(40, 130, 191, 31));
        ListGrassStadiums = new QPushButton(ListWindow);
        ListGrassStadiums->setObjectName(QStringLiteral("ListGrassStadiums"));
        ListGrassStadiums->setGeometry(QRect(40, 180, 191, 31));
        ListChronologicalStadium = new QPushButton(ListWindow);
        ListChronologicalStadium->setObjectName(QStringLiteral("ListChronologicalStadium"));
        ListChronologicalStadium->setGeometry(QRect(40, 230, 191, 31));
        listDisplayBox = new QTextBrowser(ListWindow);
        listDisplayBox->setObjectName(QStringLiteral("listDisplayBox"));
        listDisplayBox->setGeometry(QRect(300, 30, 551, 361));

        retranslateUi(ListWindow);

        QMetaObject::connectSlotsByName(ListWindow);
    } // setupUi

    void retranslateUi(QDialog *ListWindow)
    {
        ListWindow->setWindowTitle(QApplication::translate("ListWindow", "Dialog", 0));
        listAllStadiums->setText(QApplication::translate("ListWindow", "List of All Stadiums", 0));
        listAmLeagueStadiums->setText(QApplication::translate("ListWindow", "List of AL Staidiums", 0));
        listNLStadiums->setText(QApplication::translate("ListWindow", "List of NL Stadiums", 0));
        ListGrassStadiums->setText(QApplication::translate("ListWindow", "List of Stadiums with grass", 0));
        ListChronologicalStadium->setText(QApplication::translate("ListWindow", "List Stadiums Chronologically", 0));
    } // retranslateUi

};

namespace Ui {
    class ListWindow: public Ui_ListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWINDOW_H
