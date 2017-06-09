/*Trip window header file
* 
* Trip window is a second level page that opens when the user
* presses the plan a trip button
* 
* initializes vector lists, setLists/append/initialize table/ on_button_clicked functions
* 
*/


#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H
// whole thing // 6/8/2017!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <QDialog>
#include <vector>       // 06/07/2017
#include "stadiuminfo.h"
#include "souvenir.h"
#include "graph.h"

using namespace std; // don't know if need this

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

    void appendFirst(string name, int totalDistance, string league);

    void appendStad2(int index1, int index2, const vector<string> &theList, int &totalDistance, string league);

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
    //tripwindow ui
    Ui::TripWindow *ui;
    
    //vector lists
    vector<StadiumInfo> original;
    vector<StadiumInfo> stadList;
    vector<StadiumInfo> customList;
    
    //list of souvenirs
    vector<Souvenir> souvList;
    
    //boolean variable that checks whether souvenir list has been initialized
    bool souvListInitialized;

    //keeps track of the total price of the souvenirs
    double totalPrice;

    //travel map of all the stadiums
    Graph travelMap;

};

#endif // TRIPWINDOW_H
