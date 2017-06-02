#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listwindow.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>           // Added for the sorted list

#include "binarytree.h"
#include "stadiuminfo.h"
#include "date.h"

#include <vector>

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

struct Souvenir
{
private:
    string name;
    double price;
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

    void grassList();
    void alList();
    void nlList();

private slots:
    void on_ListButton_clicked();

    void on_TripsButton_clicked();

private:
    Ui::MainWindow *ui;
    ListWindow* listWindow;
    BinaryTree<StadiumInfo, StadiumComparebyTeam>* stadiumList;
    string stadInfoString;  // Added for testing purposes

    vector<StadiumInfo> sortedListFull;

};

#endif // MAINWINDOW_H
