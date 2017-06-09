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
    Ui::TripWindow *ui;
    vector<StadiumInfo> original;

    vector<StadiumInfo> stadList;
    vector<StadiumInfo> customList;

    vector<Souvenir> souvList;
    bool souvListInitialized;

    double totalPrice;

    Graph travelMap;

};

#endif // TRIPWINDOW_H
