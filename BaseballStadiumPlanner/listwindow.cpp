/*
* list window class file
* 
* contains set and append functions, print functions and info strings, and vector lists
* 
* list window is a second level page of our interface
*
*/

#include "listwindow.h"
#include "ui_listwindow.h"

ListWindow::ListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
}

//deconstructor for ui
ListWindow::~ListWindow()
{
    delete ui;
}

//by stadium name 06/07/2017
//O(1)
void ListWindow::setStadiumNameSortedList(const vector<StadiumInfo>& otherList)
{
    this->sortedStadiumNameList = otherList;
}

//by team name 06/07/2017
//O(1)
void ListWindow::setSortedStadiumList(const vector<StadiumInfo>& otherList)
{
    this->sortedList = otherList;
}

//by date opened
//O(1)
void ListWindow::setChronoList(const vector<StadiumInfo> &otherList)
{
    this->chronoList = otherList;
}

//Append stadium object to table
//O(1)
void ListWindow::appendStadium(int index, vector<StadiumInfo> theList)
{
    ui->TableWidget->setRowCount(ui->TableWidget->rowCount()+1);
    int n = ui->TableWidget->rowCount()-1;

    ui->TableWidget->setItem(n,0,new QTableWidgetItem(QString::fromStdString(theList[index].getName())));
    ui->TableWidget->setItem(n,1,new QTableWidgetItem(QString::fromStdString(theList[index].getTeam())));
    ui->TableWidget->setItem(n,2,new QTableWidgetItem(QString::fromStdString(theList[index].getCityInfo())));
    ui->TableWidget->setItem(n,3,new QTableWidgetItem(QString::fromStdString(theList[index].getOpened().getStringDate())));
    ui->TableWidget->setItem(n,4,new QTableWidgetItem(QString::fromStdString(to_string(theList[index].getCapacity()))));


    if(theList[index].hasGrass())
        ui->TableWidget->setItem(n,5,new QTableWidgetItem(QString::fromStdString("grass")));
    else
        ui->TableWidget->setItem(n,5,new QTableWidgetItem(QString::fromStdString("No grass")));

    if(theList[index].isNL())
        ui->TableWidget->setItem(n,6,new QTableWidgetItem(QString::fromStdString("National League")));
    else
        ui->TableWidget->setItem(n,6,new QTableWidgetItem(QString::fromStdString("American League")));

}

//by stadium name 06/07/2017
////O(n)
void ListWindow::printByStadiumName()
{
    initializeTableInfo();

    for(int i = 0; i < (int)sortedStadiumNameList.size();++i)
    {
        appendStadium(i, sortedStadiumNameList);
    }
}

//prints American League stadiums
//O(n)
void ListWindow::printAL()
{
    initializeTableInfo();

    for(int i = 0; i < (int)sortedList.size();++i)
    {
        if(!sortedList[i].isNL())
        {
            appendStadium(i, sortedList);
        }
    }
}

//print all stadiums by team name
//O(n)
void ListWindow::printAll()
{
    initializeTableInfo();

    for(int i = 0; i < (int)sortedList.size();++i)
    {
        appendStadium(i, sortedList);
    }
}

//print national league stadiums by team name
//O(n)
void ListWindow::printNL()
{
    initializeTableInfo();

    for(int i = 0; i < (int)sortedList.size();++i)
    {
        if(sortedList[i].isNL())
        {
            appendStadium(i, sortedList);
        }
    }
}

//print stadiums that have grass
//O(n)
void ListWindow::printGrass()
{
    initializeTableInfo();

    for(int i = 0; i < (int)sortedList.size();++i)
    {
        if(sortedList[i].hasGrass())
        {
            appendStadium(i,sortedList);
        }
    }
}

//print stadiums by date opened
//O(n)
void ListWindow::printChrono()
{
    initializeTableInfo();

    for(int i = 0; i < (int)chronoList.size();++i)
    {
        appendStadium(i, chronoList);
    }
}

//Create Table
//O(1)
void ListWindow::initializeTableInfo()
{
    ui->TableWidget->setColumnCount(7);
    ui->TableWidget->setColumnWidth(1,150);

    std::string labels = "Stadium, Team, Address, Date Opened, Capacity, Grass, Type";
    ui->TableWidget->setHorizontalHeaderLabels(QString::fromStdString(labels).split(","));

    ui->TableWidget->setRowCount(0);
}
