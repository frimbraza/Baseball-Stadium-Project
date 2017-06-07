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

    void setSortedStadiumList(const vector<StadiumInfo>& sortedList);
    void setChronoList(const vector<StadiumInfo>& otherList);
    void setAllStadiumsString(std::string input);

    void appendStadium(int index, vector<StadiumInfo> theList);

public slots:
    void printAL();
    void printAll();
    void printNL();
    void printGrass();
    void printChrono();

private slots:
    void on_listAllStadiums_clicked();

    void on_listAmLeagueStadiums_clicked();

    void on_listNLStadiums_clicked();

    void on_ListGrassStadiums_clicked();

    void on_ListChronologicalStadium_clicked();

private:
    Ui::ListWindow *ui;
    std::string AllStadInfo;
    std::string AmStadInfo;
    std::string NlStadInfo;
    std::string grassStadInfo;

    // btree;
    // StadiumInfo stad;
    vector<StadiumInfo> sortedList;
    vector<StadiumInfo> chronoList;

    void initializeTableInfo();
};

#endif // LISTWINDOW_H
