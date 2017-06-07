#ifndef ADMINFUNTION_H
#define ADMINFUNTION_H

#include <QDialog>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "binarytree.h"
#include "stadiuminfo.h"
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
struct SouvenirStruct
{
public:
    SouvenirStruct():name(""),price(0){}
    SouvenirStruct (string n, double p):name(n),price(p){}
    void setName(string n){name = n;}
    void setPrice(double p){price = p;}
    string getName(){return name;}
    string getPrice(){return to_string(price);}


private:
    string name;
    double price;
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


    void appendSouvenir(int index, vector<SouvenirStruct> theList);
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

    vector<SouvenirStruct> souvenirList;
    vector<StadiumInfo> sortedList;

    void initializeSouvenirTableInfo();
    void initializeStadiumTableInfo();
    void printAll();
    void displaySouvenir();

};

#endif // ADMINFUNTION_H
