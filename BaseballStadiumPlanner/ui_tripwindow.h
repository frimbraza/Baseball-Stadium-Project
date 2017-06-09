/********************************************************************************
** Form generated from reading UI file 'tripwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPWINDOW_H
#define UI_TRIPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_TripWindow
{
public:
    QPushButton *allTripButton;
    QPushButton *alTripButton;
    QPushButton *nlTripButton;
    QGroupBox *groupBox;
    QPushButton *addToTripButton;
    QPushButton *resetListButton;
    QComboBox *comboBox;
    QPushButton *printCustomButton;
    QTableWidget *TableWidget;
    QComboBox *comboBox_2;
    QPushButton *addSouvButton;
    QTextBrowser *totalPriceBrowser;
    QLabel *totalLabel;

    void setupUi(QDialog *TripWindow)
    {
        if (TripWindow->objectName().isEmpty())
            TripWindow->setObjectName(QStringLiteral("TripWindow"));
        TripWindow->resize(897, 615);
        allTripButton = new QPushButton(TripWindow);
        allTripButton->setObjectName(QStringLiteral("allTripButton"));
        allTripButton->setGeometry(QRect(30, 30, 231, 41));
        alTripButton = new QPushButton(TripWindow);
        alTripButton->setObjectName(QStringLiteral("alTripButton"));
        alTripButton->setGeometry(QRect(30, 90, 231, 41));
        nlTripButton = new QPushButton(TripWindow);
        nlTripButton->setObjectName(QStringLiteral("nlTripButton"));
        nlTripButton->setGeometry(QRect(30, 150, 231, 41));
        groupBox = new QGroupBox(TripWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(410, 280, 401, 231));
        addToTripButton = new QPushButton(groupBox);
        addToTripButton->setObjectName(QStringLiteral("addToTripButton"));
        addToTripButton->setGeometry(QRect(260, 20, 110, 28));
        resetListButton = new QPushButton(groupBox);
        resetListButton->setObjectName(QStringLiteral("resetListButton"));
        resetListButton->setGeometry(QRect(260, 70, 110, 28));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 221, 31));
        printCustomButton = new QPushButton(groupBox);
        printCustomButton->setObjectName(QStringLiteral("printCustomButton"));
        printCustomButton->setGeometry(QRect(260, 120, 110, 28));
        TableWidget = new QTableWidget(TripWindow);
        TableWidget->setObjectName(QStringLiteral("TableWidget"));
        TableWidget->setGeometry(QRect(380, 20, 471, 231));
        comboBox_2 = new QComboBox(TripWindow);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(30, 310, 171, 31));
        addSouvButton = new QPushButton(TripWindow);
        addSouvButton->setObjectName(QStringLiteral("addSouvButton"));
        addSouvButton->setGeometry(QRect(240, 310, 110, 28));
        totalPriceBrowser = new QTextBrowser(TripWindow);
        totalPriceBrowser->setObjectName(QStringLiteral("totalPriceBrowser"));
        totalPriceBrowser->setGeometry(QRect(240, 350, 121, 31));
        totalLabel = new QLabel(TripWindow);
        totalLabel->setObjectName(QStringLiteral("totalLabel"));
        totalLabel->setGeometry(QRect(240, 380, 91, 31));

        retranslateUi(TripWindow);

        QMetaObject::connectSlotsByName(TripWindow);
    } // setupUi

    void retranslateUi(QDialog *TripWindow)
    {
        TripWindow->setWindowTitle(QApplication::translate("TripWindow", "Dialog", 0));
        allTripButton->setText(QApplication::translate("TripWindow", "Design a trip to all Stadiums", 0));
        alTripButton->setText(QApplication::translate("TripWindow", "Design a trip to AL Stadiums", 0));
        nlTripButton->setText(QApplication::translate("TripWindow", "Design a trip to NL Stadiums", 0));
        groupBox->setTitle(QApplication::translate("TripWindow", "Design Your Own Trip", 0));
        addToTripButton->setText(QApplication::translate("TripWindow", "Add to Trip", 0));
        resetListButton->setText(QApplication::translate("TripWindow", "Reset List", 0));
        printCustomButton->setText(QApplication::translate("TripWindow", "Print Custom", 0));
        addSouvButton->setText(QApplication::translate("TripWindow", "Add Souvenir", 0));
        totalLabel->setText(QApplication::translate("TripWindow", "Total Price", 0));
    } // retranslateUi

};

namespace Ui {
    class TripWindow: public Ui_TripWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPWINDOW_H
