#include "tripwindow.h"
#include "ui_tripwindow.h"
#include <iostream>     // testing.. Remove later

TripWindow::TripWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripWindow)
{
    ui->setupUi(this);
    souvListInitialized = false;
    totalPrice = 0;

    for(int i = 0; i < 27; ++i)
    {
        travelMap.printDijkstras(i);
    }
}


//destructor
//Big O: O(1)

TripWindow::~TripWindow()
{
    delete ui;
}


//set function
//Big O: O(1)

void TripWindow::setSortedStadList(const vector<StadiumInfo> &other)
{
    stadList = other;
    original = other;
    for(int i = 0; i < (int)stadList.size(); ++i)
        ui->comboBox->addItem(QString::fromStdString(stadList[i].getName()));
}


//set function
//Big O: O(1)

void TripWindow::setSouvList(const vector<Souvenir> &other)
{
    souvList = other;
    for(int i = 0; i < (int)souvList.size(); ++i)
        ui->comboBox_2->addItem(QString::fromStdString(souvList[i].getName()));
}

//append stadiums
//Big O: O(n)

void TripWindow::appendStadium(int index, vector<StadiumInfo> theList)
{
    ui->TableWidget->setRowCount(ui->TableWidget->rowCount() + 1);
    int n  = ui->TableWidget->rowCount() - 1;


    ui->TableWidget->setItem(n, 0, new QTableWidgetItem(QString::fromStdString(theList[index].getName())));
    int distance = 5;
    QString qDistance = QString::fromStdString(to_string(distance));
    ui->TableWidget->setItem(n, 1, new QTableWidgetItem(qDistance));// go back here

    if(theList[index].isNL())
        ui->TableWidget->setItem(n, 2, new QTableWidgetItem("NL"));
    else
        ui->TableWidget->setItem(n, 2, new QTableWidgetItem("AL"));
}

//append souvenirs
//Big O: O(n)

void TripWindow::appendFirst(string name, int totalDistance, string league)
{
    ui->TableWidget->setRowCount(ui->TableWidget->rowCount() + 1);
    int n  = ui->TableWidget->rowCount() - 1;
    ui->TableWidget->setItem(n, 0, new QTableWidgetItem(QString::fromStdString(name)));
    ui->TableWidget->setItem(n, 1, new QTableWidgetItem(QString::fromStdString(to_string(totalDistance))));
    ui->TableWidget->setItem(n, 2, new QTableWidgetItem(QString::fromStdString(league)));
}

void TripWindow::appendStad2(int index1,int index2, const vector<string> &theList, int &totalDistance, string league)
{
    ui->TableWidget->setRowCount(ui->TableWidget->rowCount() + 1);
    int n  = ui->TableWidget->rowCount() - 1;

    ui->TableWidget->setItem(n, 0, new QTableWidgetItem(QString::fromStdString(theList[index2])));
    int distance = travelMap.returnDist(index1, index1+1);
    totalDistance = totalDistance + distance;
    ui->TableWidget->setItem(n, 1, new QTableWidgetItem(QString::fromStdString(to_string(totalDistance))));
    ui->TableWidget->setItem(n,2,new QTableWidgetItem(QString::fromStdString(league)));
    // come back here, for third item
}


void TripWindow::appendSouv(int index)
{
    ui->TableWidget->setRowCount(ui->TableWidget->rowCount() + 1);
    int n  = ui->TableWidget->rowCount() - 1;


    ui->TableWidget->setItem(n, 0, new QTableWidgetItem(QString::fromStdString(souvList[index].getName())));
    // cout << souvList[index].getName() << " !!!!!!!!!! " <<  endl;
    ui->TableWidget->setItem(n, 1, new QTableWidgetItem(QString::fromStdString(souvList[index].getPrice())));
}

void TripWindow::on_customTripButton_clicked()
{

}


//initialize list of stadiums table
//Big O: O(1)

void TripWindow::initializeTableInfo()
{
    ui->TableWidget->setColumnCount(3);
    ui->TableWidget->setColumnWidth(1,150);

    std::string labels = "Stadium Name, Distance Traveled, AL/NL";
    ui->TableWidget->setHorizontalHeaderLabels(QString::fromStdString(labels).split(","));

    ui->TableWidget->setRowCount(0);
}

//initialize souvenir table
//Big O: O(1)

void TripWindow::initializeSouvTable()
{
    souvListInitialized = true;

    ui->TableWidget->setColumnCount(2);
    ui->TableWidget->setColumnWidth(1,150);

    std::string labels = "Souvenir, Price";
    ui->TableWidget->setHorizontalHeaderLabels(QString::fromStdString(labels).split(","));

    ui->TableWidget->setRowCount(0);
}


//executes on add to trip
//Big O: O(1)

// 6/8/2017!!!!!!!!!!!!!!!!!!!!!!!!!!

void TripWindow::on_addToTripButton_clicked()
{
    int index = ui->comboBox->currentIndex();

    if(ui->comboBox->count() != 0)
    {
        customList.push_back(stadList[index]);
        stadList.erase(stadList.begin() + index);

        ui->comboBox->removeItem(index);
    }
}


//executes on reset
//Big O: O(1)

void TripWindow::on_resetListButton_clicked()
{
    stadList = original;
    customList.clear();
    ui->comboBox->clear();
    for(int i = 0; i < (int)stadList.size(); ++i)
        ui->comboBox->addItem(QString::fromStdString(stadList[i].getName()));
}


//executes on design a trip to all stadiums
//Big O: O(1)

void TripWindow::on_allTripButton_clicked()
{
    initializeTableInfo();
    int totalDistance = 0;
    appendFirst(travelMap.verticeList[0],0, " ");
    for(int i = 0; i < (int)travelMap.verticeList.size() - 1; ++i)
    {
        appendStad2(i, i+1, travelMap.verticeList, totalDistance, " ");
    }

//    for(int i = 0; i < (int)original.size();++i)
//    {
//        appendStadium(i, original);
//    }
}

//executes on design a trip to AL stadiums
//Big O: O(1)

void TripWindow::on_alTripButton_clicked()
{
    initializeTableInfo();
    int totalDistance = 0;

    vector<string> ALlist;
    vector<int> ALCityIndex;
    for(int i = 0; i < (int)travelMap.verticeList.size(); ++i)
    {
        string city = travelMap.verticeList[i];

        for(int j = 0; j < (int)original.size(); ++j)
        {
            if(city == original[j].getName())
                if(!original[j].isNL())
                {
                    ALlist.push_back(city);
                    ALCityIndex.push_back(i);
                }
        }
    }
    appendFirst(travelMap.verticeList[ALCityIndex[0]], 0, "AL");
    for(int i = 0; i < (int)ALlist.size() - 1; ++i)
    {
        appendStad2(ALCityIndex[i], ALCityIndex[i+1], travelMap.verticeList, totalDistance, "AL");
    }
//    for(int i = 0; i <(int)original.size(); ++i)
//    {
//        if(!original[i].isNL())
//            appendStadium(i, original);
//    }
}


//executes on design a trip to NL stadiums
//Big O: O(1)

void TripWindow::on_nlTripButton_clicked()
{
    initializeTableInfo();
    int totalDistance = 0;

    vector<string> NLlist;
    vector<int> NLCityIndex;
    for(int i = 0; i < (int)travelMap.verticeList.size(); ++i)
    {
        string city = travelMap.verticeList[i];

        for(int j = 0; j < (int)original.size(); ++j)
        {
            if(city == original[j].getName())
                if(original[j].isNL())
                {
                    NLlist.push_back(city);
                    NLCityIndex.push_back(i);
                }
        }
    }
    cout << "NLlist size:" << NLlist.size() << endl;
    appendFirst(travelMap.verticeList[NLCityIndex[0]], 0, "NL");
    for(int i = 0; i < (int)NLlist.size() - 1; ++i)
    {
        appendStad2(NLCityIndex[i], NLCityIndex[i+1], travelMap.verticeList, totalDistance, "NL");
    }
}


//executes on design a trip to custom stadiums
//Big O: O(1)

void TripWindow::on_printCustomButton_clicked()
{
    initializeTableInfo();
    int totalDistance = 0;

    vector<int> customListIndex;
    for(int i = 0; i < (int)travelMap.verticeList.size(); ++i)
    {
        string city = travelMap.verticeList[i];

        for(int j = 0; j < (int)customList.size(); ++j)
        {
            if(city == customList[j].getName())
                customListIndex.push_back(i);
        }
    }
    appendFirst(travelMap.verticeList[customListIndex[0]], 0, " ");
    for(int i = 0; i < (int)customList.size() - 1; ++i)
    {
        appendStad2(customListIndex[i], customListIndex[i+1], travelMap.verticeList, totalDistance, " ");
    }
}


//executes on add souvenir
//Big O: O(1)

void TripWindow::on_addSouvButton_clicked()
{
    if(!souvListInitialized)
        initializeSouvTable();

    int index = ui->comboBox_2->currentIndex();
    appendSouv(index);

    totalPrice += stod(souvList[index].getPrice());
    QString qPrice = QString::fromStdString(std::to_string(totalPrice));
    ui->totalPriceBrowser->setText(qPrice);
}
