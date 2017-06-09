/*
* Trip window header file
* 
* initialize on_button_clicked, lists, and setList functions
*
*
*
*/

#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H
// whole thing // 6/8/2017!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <QDialog>
#include <vector>       // 06/07/2017
#include "stadiuminfo.h"
#include "souvenir.h"

namespace Ui {
class TripWindow;
}

class TripWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TripWindow(QWidget *parent = 0);
    ~TripWindow();

    void setSortedStadList(const vector<StadiumInfo>& other);

    void setSouvList(const vector<Souvenir>& other);

    void appendStadium(int index, vector<StadiumInfo> theList);

    void appendSouv(int index);

    void initializeTableInfo();

    void initializeSouvTable();

private slots:
    void on_customTripButton_clicked();

    void on_addToTripButton_clicked();

    void on_resetListButton_clicked();

    void on_allTripButton_clicked();

    void on_alTripButton_clicked();

    void on_nlTripButton_clicked();

    void on_printCustomButton_clicked();

    void on_addSouvButton_clicked();

private:
    Ui::TripWindow *ui;
    
    //list of stadiums
    vector<StadiumInfo> original;

    //copy of original
    vector<StadiumInfo> stadList;

    //list of either NL or AL stadiums
    vector<StadiumInfo> customList;

    //list of souvenirs
    vector<Souvenir> souvList;
    
    //boolean variable to check if souvList
    //has been initilized or not
    bool souvListInitialized;

    //tracks total price for selected souvenirs
    double totalPrice;
};

#endif // TRIPWINDOW_H
