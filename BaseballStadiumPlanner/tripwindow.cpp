/*
* Trip window class file
* 
* Trip window is a a second screen that opens when design a trip is selected
*
* contains on_button_clicked, lists, and setList functions
*
*/

#include "tripwindow.h"
#include "ui_tripwindow.h"
#include <iostream>     // testing.. Remove later

//TripWindow Widget
TripWindow::TripWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripWindow)
{
    ui->setupUi(this);
    souvListInitialized = false;
    totalPrice = 0;
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
    for(int i = 0; i < (int)original.size();++i)
    {
        appendStadium(i, original);
    }
}

//executes on design a trip to AL stadiums
//Big O: O(1)
void TripWindow::on_alTripButton_clicked()
{
    initializeTableInfo();
    for(int i = 0; i <(int)original.size(); ++i)
    {
        if(!original[i].isNL())
            appendStadium(i, original);
    }
}

//executes on design a trip to NL stadiums
//Big O: O(1)
void TripWindow::on_nlTripButton_clicked()
{
    initializeTableInfo();
    for(int i = 0; i <(int)original.size(); ++i)
    {
        if(original[i].isNL())
            appendStadium(i, original);
    }
}

//executes on design a trip to custom stadiums
//Big O: O(1)
void TripWindow::on_printCustomButton_clicked()
{
    initializeTableInfo();
    for(int i = 0; i < (int)customList.size(); ++i)
    {
        appendStadium(i,customList);
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
