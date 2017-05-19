/********************************************************************************
** Form generated from reading UI file 'tripwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPWINDOW_H
#define UI_TRIPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TripWindow
{
public:
    QPushButton *allTripButton;
    QPushButton *alTripButton;
    QPushButton *nlTripButton;
    QPushButton *customTripButton;

    void setupUi(QDialog *TripWindow)
    {
        if (TripWindow->objectName().isEmpty())
            TripWindow->setObjectName(QStringLiteral("TripWindow"));
        TripWindow->resize(565, 374);
        allTripButton = new QPushButton(TripWindow);
        allTripButton->setObjectName(QStringLiteral("allTripButton"));
        allTripButton->setGeometry(QRect(30, 30, 231, 41));
        alTripButton = new QPushButton(TripWindow);
        alTripButton->setObjectName(QStringLiteral("alTripButton"));
        alTripButton->setGeometry(QRect(30, 90, 231, 41));
        nlTripButton = new QPushButton(TripWindow);
        nlTripButton->setObjectName(QStringLiteral("nlTripButton"));
        nlTripButton->setGeometry(QRect(30, 150, 231, 41));
        customTripButton = new QPushButton(TripWindow);
        customTripButton->setObjectName(QStringLiteral("customTripButton"));
        customTripButton->setGeometry(QRect(30, 210, 231, 41));

        retranslateUi(TripWindow);

        QMetaObject::connectSlotsByName(TripWindow);
    } // setupUi

    void retranslateUi(QDialog *TripWindow)
    {
        TripWindow->setWindowTitle(QApplication::translate("TripWindow", "Dialog", 0));
        allTripButton->setText(QApplication::translate("TripWindow", "Design a trip to all Stadiums", 0));
        alTripButton->setText(QApplication::translate("TripWindow", "Design a trip to AL Stadiums", 0));
        nlTripButton->setText(QApplication::translate("TripWindow", "Design a trip to NL Stadiums", 0));
        customTripButton->setText(QApplication::translate("TripWindow", "Design your own trip", 0));
    } // retranslateUi

};

namespace Ui {
    class TripWindow: public Ui_TripWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPWINDOW_H
