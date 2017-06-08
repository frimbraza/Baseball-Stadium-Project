#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listwindow.h"
#include "adminlogin.h"
#include "adminfuntion.h"
#include "tripwindow.h"// 6/8/2017!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <fstream>
#include <iostream>     //remove when we're done
#include <string>
#include "binarytree.h"
#include "stadiuminfo.h"
#include "souvenir.h"
#include "date.h"

struct StadiumComparebyTeam
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

struct CompareByStadiumName
{
    bool operator()(StadiumInfo first, StadiumInfo second)
    {
        int compareValue = first.getName().compare(second.getName());
        //cout << first.getName() << " & " << second.getName() << endl;
        if(compareValue < 0)
            return true;
        else
            return false;
    }
};

struct CompareByDate
{
    bool operator()(StadiumInfo first, StadiumInfo second)
    {
        return first.getOpened() < second.getOpened();
    }
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SkipBOM(std::ifstream &in);       // 6/7/2017

    // Fix these up to be compatible with the GUI; complete
    BinaryTree<StadiumInfo, StadiumComparebyTeam> sortByTeamName();
    BinaryTree<StadiumInfo, StadiumComparebyTeam> sortByStadiumName();
    BinaryTree<StadiumInfo, StadiumComparebyTeam> sortByDate();
    void readFromFile();
    void addSouvenirList();

    void grassList();
    void alList();
    void nlList();


private slots:
    void on_ListButton_clicked();

    void on_TripsButton_clicked();

    void on_AdminButton_clicked();

    void on_UpdateButton_clicked();

private:
    Ui::MainWindow *ui;
    ListWindow* listWindow;
    adminLogin* AdminLogin;
    TripWindow* tripWindow;// 6/8/2017!!!!!!!!!!!!!!!!!!!!!!!!!!

    BinaryTree<StadiumInfo, StadiumComparebyTeam>* stadiumList;
    string stadInfoString;  // Added for testing purposes

    // vector<string> stadiumNameList;             // 6/7/2017

    // vector<int> shortStadiums;
    // vector<int> shortALStadiums;
    // vector<int> shortNLStadiums;
    
    vector<Souvenir> souvenirList;


};

#endif // MAINWINDOW_H
