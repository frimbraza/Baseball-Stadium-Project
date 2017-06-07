#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listwindow.h"
#include "adminlogin.h"
#include "adminfuntion.h"

#include <fstream>
#include <iostream>
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
    // Fix these up to be compatible with the GUI
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


    BinaryTree<StadiumInfo, StadiumComparebyTeam>* stadiumList;
    string stadInfoString;  // Added for testing purposes

    vector<string> stadiumNameList;

    vector<int> shortStadiums;
    vector<int> shortALStadiums;
    vector<int> shortNLStadiums;
    
    vector<Souvenir> souvenirList;


};

#endif // MAINWINDOW_H
