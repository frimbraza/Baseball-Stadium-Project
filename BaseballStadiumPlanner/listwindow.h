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

    void setSortedStadiumList(const vector<StadiumInfo>& sortedList);//construct list by team name
    void setChronoList(const vector<StadiumInfo>& otherList);//construct list by date opened
//    void setAllStadiumsString(std::string input);

    void appendStadium(int index, vector<StadiumInfo> theList);//add stadium to list

public slots:
    void printByStadiumName();      //construct list by stadium name
    void printAL();                 
    void printAll();                
    void printNL();
    void printGrass();
    void printChrono();


private:
    Ui::ListWindow *ui;
//    std::string AllStadInfo;
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
