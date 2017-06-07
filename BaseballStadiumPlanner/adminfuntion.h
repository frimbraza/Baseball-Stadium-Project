#ifndef ADMINFUNTION_H
#define ADMINFUNTION_H

#include <QDialog>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "binarytree.h"
#include "stadiuminfo.h"
#include "souvenir.h"
#include "date.h"


struct StadiumComparebyTeamName
{
    bool operator()(StadiumInfo first, StadiumInfo second)
    {
        int compareValue = first.getTeam().compare(second.getTeam());
        if (compareValue < 0)
            return true;
        else
            return false;
    }
};


namespace Ui {
class adminFuntion;
}

class adminFuntion : public QDialog
{
    Q_OBJECT

public:
    explicit adminFuntion(QWidget *parent = 0);
    ~adminFuntion();
    void readFromFile();
    void addSouvenirList();
    void saveAtNewSouvnierFile();
    void saveAtNewStadiumFile();


    void appendSouvenir(int index, vector<Souvenir> theList);
    void appendStadium(int index, vector<StadiumInfo> theList);

    void setSortedStadiumList(const vector<StadiumInfo>& sortedList);


private slots:
    void on_Display_clicked();

    void on_Add_Souvenir_clicked();

    void on_Delete_Souvenir_clicked();

    void on_Change_Souvenir_clicked();

    void on_AddNewTeam_clicked();

    void on_Display_Stadium_List_1_clicked();

    void on_Display_Stadium_List_clicked();

    void on_AddNewStadium_clicked();

private:
    Ui::adminFuntion *ui;
    BinaryTree<StadiumInfo, StadiumComparebyTeamName>* stadiumList;

    vector<Souvenir> souvenirList;
    vector<StadiumInfo> sortedList;

    void initializeSouvenirTableInfo();
    void initializeStadiumTableInfo();
    void printAll();
    void displaySouvenir();

};

#endif // ADMINFUNTION_H
