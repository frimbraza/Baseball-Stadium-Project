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


/****************************************************
struct StadiumComparebyTeamName
_____________________________________________________
Compares the team name of object StadiumInfo and 
returns boolean
*****************************************************/
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

/****************************************************
class adminFuntion
_____________________________________________________
class for admin functions that contains slots, functions,
member variables, and ui constructor
*****************************************************/
namespace Ui {
class adminFuntion;
}

class adminFuntion : public QDialog
{
    Q_OBJECT

public:
    explicit adminFuntion(QWidget *parent = 0);
    ~adminFuntion();
    
    void readFromFile();            //takes input from file, intializes tree and lists
    void addSouvenirList();         //creates souvenir list
    void saveAtNewSouvnierFile();   //creates changes to souvenir file
    void saveAtNewStadiumFile();    //creates changes to stadium file


    void appendSouvenir(int index, vector<Souvenir> theList);   //appends souviner items to table
    void appendStadium(int index, vector<StadiumInfo> theList); //appends stadiums items to the table

    void setSortedStadiumList(const vector<StadiumInfo>& sortedList);   //creates sorted stadium list


private slots:
    void on_Display_clicked();                  //display button to display souvenirs

    void on_Add_Souvenir_clicked();             //adds souvenirs and appends to table

    void on_Delete_Souvenir_clicked();          //deletes souvenirs

    void on_Change_Souvenir_clicked();          //creates changes to a souvenir

    void on_AddNewTeam_clicked();               //add new team 

    void on_Display_Stadium_List_1_clicked();   //display stadium list 1

    void on_Display_Stadium_List_clicked();     //display stadium list

    void on_AddNewStadium_clicked();            //adds new stadium

private:
    Ui::adminFuntion *ui;
    BinaryTree<StadiumInfo, StadiumComparebyTeamName>* stadiumList;

    vector<Souvenir> souvenirList;
    vector<StadiumInfo> sortedList;

    void initializeSouvenirTableInfo();     //intialize souvenir table
    void initializeStadiumTableInfo();      //intialize stadium table
    void printAll();                        //prints table
    void displaySouvenir();                 //displays souvenir

};

#endif // ADMINFUNTION_H
