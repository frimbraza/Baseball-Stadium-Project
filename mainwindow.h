#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <iostream>
#include <string>
#include "binarytree.h"
#include "stadiuminfo.h"
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

private:
    Ui::MainWindow *ui;
    BinaryTree<StadiumInfo, StadiumComparebyTeam>* stadiumList;


};

#endif // MAINWINDOW_H
