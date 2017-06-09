/*
* list window header file
* 
* initializes set and append functions, print functions and info strings, and vector lists
* 
* list window is a second level page of our interface
*
*/

#ifndef LISTWINDOW_H
#define LISTWINDOW_H

#include <QDialog>
// #include "mainwindow.h" // remember you added this. Should remove later
#include <string>
#include "stadiuminfo.h"
#include "binarytree.h"

namespace Ui {
class ListWindow;
}

class ListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ListWindow(QWidget *parent = 0);
    ~ListWindow();

    void setStadiumNameSortedList(const vector<StadiumInfo>& otherList);// Added 6/7/2017

    void setSortedStadiumList(const vector<StadiumInfo>& sortedList);
    void setChronoList(const vector<StadiumInfo>& otherList);

    void appendStadium(int index, vector<StadiumInfo> theList);

public slots:
    void printByStadiumName();      // Added 6/7/2017
    void printAL();
    void printAll();
    void printNL();
    void printGrass();
    void printChrono();

private:
    Ui::ListWindow *ui;
    std::string AmStadInfo;
    std::string NlStadInfo;
    std::string grassStadInfo;

    // btree;
    // StadiumInfo stad;
    vector<StadiumInfo> sortedStadiumNameList;  // Added 6/7/2017
    vector<StadiumInfo> sortedList;
    vector<StadiumInfo> chronoList;

    void initializeTableInfo();
};

#endif // LISTWINDOW_H
