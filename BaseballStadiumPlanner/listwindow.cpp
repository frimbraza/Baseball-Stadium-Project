#include "listwindow.h"
#include "ui_listwindow.h"

ListWindow::ListWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
}

ListWindow::~ListWindow()
{
    delete ui;
}

void ListWindow::setSortedStadiumList(const vector<StadiumInfo>& otherList)
{
    this->sortedList = otherList;
}

void ListWindow::setChronoList(const vector<StadiumInfo> &otherList)
{
    this->chronoList = otherList;
}

void ListWindow::setAllStadiumsString(std::string input)
{
    AllStadInfo = input;
}

void ListWindow::on_listAllStadiums_clicked()
{
    // Note that QT is really dumb, and has it's own QString. It won't take real strings
    //ui->listDisplayBox->setText(QString::fromStdString(AllStadInfo));
}


void ListWindow::on_listAmLeagueStadiums_clicked()
{
    //ui->listDisplayBox->setText("The list of AL stadiums go here.");
}

void ListWindow::on_listNLStadiums_clicked()
{
    //ui->listDisplayBox->setText("NL List.\n1) dodger\n2)Angel\n3)Test\n");
}

void ListWindow::on_ListGrassStadiums_clicked()
{
    //ui->listDisplayBox->setText("So Grassy. Much Grass.");
}

void ListWindow::on_ListChronologicalStadium_clicked()
{
    //ui->listDisplayBox->setText("List the stadiums chronolocially.");
}

void ListWindow::appendStadium(int index, vector<StadiumInfo> theList)
{
    ui->TableWidget->setRowCount(ui->TableWidget->rowCount()+1);
    int n = ui->TableWidget->rowCount()-1;

    ui->TableWidget->setItem(n,0,new QTableWidgetItem(QString::fromStdString(theList[index].getName())));
    ui->TableWidget->setItem(n,1,new QTableWidgetItem(QString::fromStdString(theList[index].getTeam())));
    ui->TableWidget->setItem(n,2,new QTableWidgetItem(QString::fromStdString(theList[index].getCityInfo())));
    ui->TableWidget->setItem(n,3,new QTableWidgetItem(QString::fromStdString(theList[index].getOpened())));
    if(theList[index].hasGrass())
        ui->TableWidget->setItem(n,4,new QTableWidgetItem(QString::fromStdString("grass")));
    else
        ui->TableWidget->setItem(n,4,new QTableWidgetItem(QString::fromStdString("No grass")));

    if(theList[index].isNL())
        ui->TableWidget->setItem(n,5,new QTableWidgetItem(QString::fromStdString("National League")));
    else
        ui->TableWidget->setItem(n,5,new QTableWidgetItem(QString::fromStdString("American League")));

}

void ListWindow::printAL()
{
    initializeTableInfo();

    for(int i = 0; i < sortedList.size();++i)
    {
        if(!sortedList[i].isNL())
        {
            appendStadium(i, sortedList);
        }
    }
}

void ListWindow::printAll()
{
    initializeTableInfo();

    for(int i = 0; i < sortedList.size();++i)
    {
        appendStadium(i, sortedList);
    }
}

void ListWindow::printNL()
{
    initializeTableInfo();

    for(int i = 0; i < sortedList.size();++i)
    {
        if(sortedList[i].isNL())
        {
            appendStadium(i, sortedList);
        }
    }
}

void ListWindow::printGrass()
{
    initializeTableInfo();

    for(int i = 0; i < sortedList.size();++i)
    {
        if(sortedList[i].hasGrass())
        {
            appendStadium(i,sortedList);
        }
    }
}

void ListWindow::printChrono()
{
    initializeTableInfo();

    for(int i = 0; i < chronoList.size();++i)
    {
        appendStadium(i, chronoList);
    }
}

void ListWindow::initializeTableInfo()
{
    ui->TableWidget->setColumnCount(6);
    ui->TableWidget->setColumnWidth(1,150);

    std::string labels = "Stadium, Team, Address, Date Opened, Grass, Type";
    ui->TableWidget->setHorizontalHeaderLabels(QString::fromStdString(labels).split(","));

    ui->TableWidget->setRowCount(0);
}
