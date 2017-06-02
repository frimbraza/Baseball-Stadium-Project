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

void ListWindow::appendStadium(int index)
{
    ui->TableWidget->setRowCount(ui->TableWidget->rowCount()+1);
    int n = ui->TableWidget->rowCount()-1;

    ui->TableWidget->setItem(n,0,new QTableWidgetItem(QString::fromStdString("//Standium Name at index")));
    ui->TableWidget->setItem(n,1,new QTableWidgetItem(QString::fromStdString("//Team Name at index")));
    ui->TableWidget->setItem(n,2,new QTableWidgetItem(QString::fromStdString("//address")));
}

void ListWindow::printAL()
{
     ui->TableWidget->setColumnCount(3);
     ui->TableWidget->setColumnWidth(1,150);

     std::string labels = "Stadium, Team, Adress";
     ui->TableWidget->setHorizontalHeaderLabels(QString::fromStdString(labels).split(","));

     ui->TableWidget->setRowCount(1);

     ui->TableWidget->setItem(0,0,new QTableWidgetItem(QString::fromStdString("Staples Center")));
     ui->TableWidget->setItem(0,1,new QTableWidgetItem(QString::fromStdString("LA Lakers")));
     ui->TableWidget->setItem(0,2,new QTableWidgetItem(QString::fromStdString("Los Angeles")));

     ui->TableWidget->setRowCount(ui->TableWidget->rowCount()+1);


     ui->TableWidget->setItem(1,0,new QTableWidgetItem(QString::fromStdString("Staples Center")));
     ui->TableWidget->setItem(1,1,new QTableWidgetItem(QString::fromStdString("LA Lakers")));
     ui->TableWidget->setItem(1,2,new QTableWidgetItem(QString::fromStdString("Los Angeles")));

//     for(int i = 0; i < btree.getSize();i++)
//     {
//         if(!stad.isNL())
//         {
//             appendStadium(i);
//         }
//     }
}
