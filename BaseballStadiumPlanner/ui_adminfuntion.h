/********************************************************************************
** Form generated from reading UI file 'adminfuntion.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFUNTION_H
#define UI_ADMINFUNTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminFuntion
{
public:
    QTabWidget *tabWidget;
    QWidget *NewStadium;
    QGroupBox *groupBox_5;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_NewStadium;
    QLineEdit *lineEdit_NewTeam;
    QLineEdit *lineEdit_Street;
    QLineEdit *lineEdit_CityInfo;
    QLineEdit *lineEdit_PhoneNum;
    QLineEdit *lineEdit_Capacity;
    QLineEdit *lineEdit_Year;
    QPushButton *AddNewStadium;
    QComboBox *comboBox_Month;
    QComboBox *comboBox_Day;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QGroupBox *groupBox_6;
    QRadioButton *haveGrass;
    QRadioButton *noGrass;
    QGroupBox *groupBox_7;
    QRadioButton *NL;
    QRadioButton *AL;
    QPushButton *Display_Stadium_List_1;
    QWidget *New_Team;
    QGroupBox *groupBox_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_TeamSwitch;
    QLineEdit *lineEdit_StadiumSwitch;
    QPushButton *AddNewTeam;
    QPushButton *Display_Stadium_List;
    QWidget *Souvenir_List;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Add_Souvenir;
    QLineEdit *lineEdit_AddName;
    QLineEdit *lineEdit_AddPrice;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLineEdit *lineEdit_deleteName;
    QPushButton *Delete_Souvenir;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_ChangeName;
    QLineEdit *lineEdit_ChangePrice;
    QPushButton *Change_Souvenir;
    QPushButton *Display;
    QTableWidget *tableWidget;

    void setupUi(QDialog *adminFuntion)
    {
        if (adminFuntion->objectName().isEmpty())
            adminFuntion->setObjectName(QStringLiteral("adminFuntion"));
        adminFuntion->resize(894, 732);
        tabWidget = new QTabWidget(adminFuntion);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 10, 310, 701));
        NewStadium = new QWidget();
        NewStadium->setObjectName(QStringLiteral("NewStadium"));
        groupBox_5 = new QGroupBox(NewStadium);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 10, 270, 550));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 30, 100, 16));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 60, 90, 16));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 90, 51, 16));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 120, 51, 16));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 150, 110, 16));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 180, 61, 16));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 210, 100, 16));
        lineEdit_NewStadium = new QLineEdit(groupBox_5);
        lineEdit_NewStadium->setObjectName(QStringLiteral("lineEdit_NewStadium"));
        lineEdit_NewStadium->setGeometry(QRect(130, 30, 130, 20));
        lineEdit_NewTeam = new QLineEdit(groupBox_5);
        lineEdit_NewTeam->setObjectName(QStringLiteral("lineEdit_NewTeam"));
        lineEdit_NewTeam->setGeometry(QRect(130, 60, 130, 20));
        lineEdit_Street = new QLineEdit(groupBox_5);
        lineEdit_Street->setObjectName(QStringLiteral("lineEdit_Street"));
        lineEdit_Street->setGeometry(QRect(130, 90, 130, 20));
        lineEdit_CityInfo = new QLineEdit(groupBox_5);
        lineEdit_CityInfo->setObjectName(QStringLiteral("lineEdit_CityInfo"));
        lineEdit_CityInfo->setGeometry(QRect(130, 120, 130, 20));
        lineEdit_PhoneNum = new QLineEdit(groupBox_5);
        lineEdit_PhoneNum->setObjectName(QStringLiteral("lineEdit_PhoneNum"));
        lineEdit_PhoneNum->setGeometry(QRect(130, 150, 130, 20));
        lineEdit_Capacity = new QLineEdit(groupBox_5);
        lineEdit_Capacity->setObjectName(QStringLiteral("lineEdit_Capacity"));
        lineEdit_Capacity->setGeometry(QRect(130, 180, 130, 20));
        lineEdit_Year = new QLineEdit(groupBox_5);
        lineEdit_Year->setObjectName(QStringLiteral("lineEdit_Year"));
        lineEdit_Year->setGeometry(QRect(130, 300, 100, 20));
        AddNewStadium = new QPushButton(groupBox_5);
        AddNewStadium->setObjectName(QStringLiteral("AddNewStadium"));
        AddNewStadium->setGeometry(QRect(90, 490, 91, 41));
        comboBox_Month = new QComboBox(groupBox_5);
        comboBox_Month->setObjectName(QStringLiteral("comboBox_Month"));
        comboBox_Month->setGeometry(QRect(130, 240, 100, 22));
        comboBox_Day = new QComboBox(groupBox_5);
        comboBox_Day->setObjectName(QStringLiteral("comboBox_Day"));
        comboBox_Day->setGeometry(QRect(130, 270, 100, 22));
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(70, 240, 47, 13));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(70, 270, 47, 13));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(70, 300, 47, 13));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 320, 250, 80));
        haveGrass = new QRadioButton(groupBox_6);
        haveGrass->setObjectName(QStringLiteral("haveGrass"));
        haveGrass->setGeometry(QRect(120, 20, 110, 17));
        noGrass = new QRadioButton(groupBox_6);
        noGrass->setObjectName(QStringLiteral("noGrass"));
        noGrass->setGeometry(QRect(120, 50, 82, 17));
        noGrass->setCheckable(true);
        noGrass->setChecked(false);
        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 400, 250, 80));
        NL = new QRadioButton(groupBox_7);
        NL->setObjectName(QStringLiteral("NL"));
        NL->setGeometry(QRect(120, 50, 140, 17));
        AL = new QRadioButton(groupBox_7);
        AL->setObjectName(QStringLiteral("AL"));
        AL->setGeometry(QRect(120, 20, 150, 17));
        Display_Stadium_List_1 = new QPushButton(NewStadium);
        Display_Stadium_List_1->setObjectName(QStringLiteral("Display_Stadium_List_1"));
        Display_Stadium_List_1->setGeometry(QRect(80, 570, 161, 91));
        tabWidget->addTab(NewStadium, QString());
        New_Team = new QWidget();
        New_Team->setObjectName(QStringLiteral("New_Team"));
        groupBox_4 = new QGroupBox(New_Team);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 20, 270, 171));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 40, 100, 16));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 80, 110, 16));
        lineEdit_TeamSwitch = new QLineEdit(groupBox_4);
        lineEdit_TeamSwitch->setObjectName(QStringLiteral("lineEdit_TeamSwitch"));
        lineEdit_TeamSwitch->setGeometry(QRect(130, 40, 130, 20));
        lineEdit_StadiumSwitch = new QLineEdit(groupBox_4);
        lineEdit_StadiumSwitch->setObjectName(QStringLiteral("lineEdit_StadiumSwitch"));
        lineEdit_StadiumSwitch->setGeometry(QRect(130, 80, 130, 20));
        AddNewTeam = new QPushButton(groupBox_4);
        AddNewTeam->setObjectName(QStringLiteral("AddNewTeam"));
        AddNewTeam->setGeometry(QRect(90, 120, 75, 31));
        Display_Stadium_List = new QPushButton(New_Team);
        Display_Stadium_List->setObjectName(QStringLiteral("Display_Stadium_List"));
        Display_Stadium_List->setGeometry(QRect(70, 220, 161, 91));
        tabWidget->addTab(New_Team, QString());
        Souvenir_List = new QWidget();
        Souvenir_List->setObjectName(QStringLiteral("Souvenir_List"));
        groupBox = new QGroupBox(Souvenir_List);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 270, 161));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 60, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 47, 13));
        Add_Souvenir = new QPushButton(groupBox);
        Add_Souvenir->setObjectName(QStringLiteral("Add_Souvenir"));
        Add_Souvenir->setGeometry(QRect(100, 110, 80, 23));
        lineEdit_AddName = new QLineEdit(groupBox);
        lineEdit_AddName->setObjectName(QStringLiteral("lineEdit_AddName"));
        lineEdit_AddName->setGeometry(QRect(100, 30, 140, 20));
        lineEdit_AddPrice = new QLineEdit(groupBox);
        lineEdit_AddPrice->setObjectName(QStringLiteral("lineEdit_AddPrice"));
        lineEdit_AddPrice->setGeometry(QRect(100, 70, 140, 20));
        groupBox_2 = new QGroupBox(Souvenir_List);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 200, 270, 151));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 50, 47, 13));
        lineEdit_deleteName = new QLineEdit(groupBox_2);
        lineEdit_deleteName->setObjectName(QStringLiteral("lineEdit_deleteName"));
        lineEdit_deleteName->setGeometry(QRect(100, 50, 140, 20));
        Delete_Souvenir = new QPushButton(groupBox_2);
        Delete_Souvenir->setObjectName(QStringLiteral("Delete_Souvenir"));
        Delete_Souvenir->setGeometry(QRect(100, 100, 75, 23));
        groupBox_3 = new QGroupBox(Souvenir_List);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 370, 270, 170));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 40, 47, 13));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 80, 47, 13));
        lineEdit_ChangeName = new QLineEdit(groupBox_3);
        lineEdit_ChangeName->setObjectName(QStringLiteral("lineEdit_ChangeName"));
        lineEdit_ChangeName->setGeometry(QRect(100, 40, 140, 20));
        lineEdit_ChangePrice = new QLineEdit(groupBox_3);
        lineEdit_ChangePrice->setObjectName(QStringLiteral("lineEdit_ChangePrice"));
        lineEdit_ChangePrice->setGeometry(QRect(100, 80, 140, 20));
        Change_Souvenir = new QPushButton(groupBox_3);
        Change_Souvenir->setObjectName(QStringLiteral("Change_Souvenir"));
        Change_Souvenir->setGeometry(QRect(90, 120, 75, 23));
        Display = new QPushButton(Souvenir_List);
        Display->setObjectName(QStringLiteral("Display"));
        Display->setGeometry(QRect(80, 560, 140, 90));
        tabWidget->addTab(Souvenir_List, QString());
        tableWidget = new QTableWidget(adminFuntion);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(360, 30, 511, 681));

        retranslateUi(adminFuntion);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(adminFuntion);
    } // setupUi

    void retranslateUi(QDialog *adminFuntion)
    {
        adminFuntion->setWindowTitle(QApplication::translate("adminFuntion", "Dialog", 0));
        groupBox_5->setTitle(QApplication::translate("adminFuntion", "Add New Stadium", 0));
        label_8->setText(QApplication::translate("adminFuntion", "Stadium Name", 0));
        label_9->setText(QApplication::translate("adminFuntion", "Team Name", 0));
        label_10->setText(QApplication::translate("adminFuntion", "Street", 0));
        label_11->setText(QApplication::translate("adminFuntion", "City Info", 0));
        label_12->setText(QApplication::translate("adminFuntion", "Phone Number", 0));
        label_13->setText(QApplication::translate("adminFuntion", "Capacity", 0));
        label_14->setText(QApplication::translate("adminFuntion", "Opened Date", 0));
        AddNewStadium->setText(QApplication::translate("adminFuntion", "Add", 0));
        comboBox_Month->clear();
        comboBox_Month->insertItems(0, QStringList()
         << QApplication::translate("adminFuntion", "January", 0)
         << QApplication::translate("adminFuntion", "February", 0)
         << QApplication::translate("adminFuntion", "March", 0)
         << QApplication::translate("adminFuntion", "April", 0)
         << QApplication::translate("adminFuntion", "May", 0)
         << QApplication::translate("adminFuntion", "June", 0)
         << QApplication::translate("adminFuntion", "July", 0)
         << QApplication::translate("adminFuntion", "August", 0)
         << QApplication::translate("adminFuntion", "September", 0)
         << QApplication::translate("adminFuntion", "October", 0)
         << QApplication::translate("adminFuntion", "November", 0)
         << QApplication::translate("adminFuntion", "December", 0)
        );
        comboBox_Day->clear();
        comboBox_Day->insertItems(0, QStringList()
         << QApplication::translate("adminFuntion", "1", 0)
         << QApplication::translate("adminFuntion", "2", 0)
         << QApplication::translate("adminFuntion", "3", 0)
         << QApplication::translate("adminFuntion", "4", 0)
         << QApplication::translate("adminFuntion", "5", 0)
         << QApplication::translate("adminFuntion", "6", 0)
         << QApplication::translate("adminFuntion", "7", 0)
         << QApplication::translate("adminFuntion", "8", 0)
         << QApplication::translate("adminFuntion", "9", 0)
         << QApplication::translate("adminFuntion", "10", 0)
         << QApplication::translate("adminFuntion", "11", 0)
         << QApplication::translate("adminFuntion", "12", 0)
         << QApplication::translate("adminFuntion", "13", 0)
         << QApplication::translate("adminFuntion", "14", 0)
         << QApplication::translate("adminFuntion", "15", 0)
         << QApplication::translate("adminFuntion", "16", 0)
         << QApplication::translate("adminFuntion", "17", 0)
         << QApplication::translate("adminFuntion", "18", 0)
         << QApplication::translate("adminFuntion", "19", 0)
         << QApplication::translate("adminFuntion", "20", 0)
         << QApplication::translate("adminFuntion", "21", 0)
         << QApplication::translate("adminFuntion", "22", 0)
         << QApplication::translate("adminFuntion", "23", 0)
         << QApplication::translate("adminFuntion", "24", 0)
         << QApplication::translate("adminFuntion", "25", 0)
         << QApplication::translate("adminFuntion", "26", 0)
         << QApplication::translate("adminFuntion", "27", 0)
         << QApplication::translate("adminFuntion", "28", 0)
         << QApplication::translate("adminFuntion", "29", 0)
         << QApplication::translate("adminFuntion", "30", 0)
         << QApplication::translate("adminFuntion", "31", 0)
        );
        label_17->setText(QApplication::translate("adminFuntion", "Month", 0));
        label_18->setText(QApplication::translate("adminFuntion", "Day", 0));
        label_19->setText(QApplication::translate("adminFuntion", "Year", 0));
        groupBox_6->setTitle(QApplication::translate("adminFuntion", "Grass", 0));
        haveGrass->setText(QApplication::translate("adminFuntion", "Have Grass", 0));
        noGrass->setText(QApplication::translate("adminFuntion", "No Grass", 0));
        groupBox_7->setTitle(QApplication::translate("adminFuntion", "AL / NL", 0));
        NL->setText(QApplication::translate("adminFuntion", "National League", 0));
        AL->setText(QApplication::translate("adminFuntion", "American League", 0));
        Display_Stadium_List_1->setText(QApplication::translate("adminFuntion", "Display List", 0));
        tabWidget->setTabText(tabWidget->indexOf(NewStadium), QApplication::translate("adminFuntion", "New Stadium", 0));
        groupBox_4->setTitle(QApplication::translate("adminFuntion", "Add New Team", 0));
        label_6->setText(QApplication::translate("adminFuntion", "Team Name", 0));
        label_7->setText(QApplication::translate("adminFuntion", "Stadium Name", 0));
        AddNewTeam->setText(QApplication::translate("adminFuntion", "Add", 0));
        Display_Stadium_List->setText(QApplication::translate("adminFuntion", "Display List", 0));
        tabWidget->setTabText(tabWidget->indexOf(New_Team), QApplication::translate("adminFuntion", "New Team", 0));
        groupBox->setTitle(QApplication::translate("adminFuntion", "Add Souvenir", 0));
        label->setText(QApplication::translate("adminFuntion", "Name", 0));
        label_2->setText(QApplication::translate("adminFuntion", "Price", 0));
        Add_Souvenir->setText(QApplication::translate("adminFuntion", "Add", 0));
        groupBox_2->setTitle(QApplication::translate("adminFuntion", "Delete Souvenir", 0));
        label_3->setText(QApplication::translate("adminFuntion", "Name", 0));
        Delete_Souvenir->setText(QApplication::translate("adminFuntion", "Delete", 0));
        groupBox_3->setTitle(QApplication::translate("adminFuntion", "Change Souvenir", 0));
        label_4->setText(QApplication::translate("adminFuntion", "Name", 0));
        label_5->setText(QApplication::translate("adminFuntion", "Price", 0));
        Change_Souvenir->setText(QApplication::translate("adminFuntion", "Change", 0));
        Display->setText(QApplication::translate("adminFuntion", "Display List", 0));
        tabWidget->setTabText(tabWidget->indexOf(Souvenir_List), QApplication::translate("adminFuntion", "Souvenir List", 0));
    } // retranslateUi

};

namespace Ui {
    class adminFuntion: public Ui_adminFuntion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFUNTION_H
