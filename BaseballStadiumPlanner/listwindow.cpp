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
    ui->listDisplayBox->setText(QString::fromStdString(AllStadInfo));
}


void ListWindow::on_listAmLeagueStadiums_clicked()
{
    ui->listDisplayBox->setText("The list of AL stadiums go here.");
}

void ListWindow::on_listNLStadiums_clicked()
{
    ui->listDisplayBox->setText("NL List.\n1) dodger\n2)Angel\n3)Test\n");
}

void ListWindow::on_ListGrassStadiums_clicked()
{
    ui->listDisplayBox->setText("So Grassy. Much Grass.");
}

void ListWindow::on_ListChronologicalStadium_clicked()
{
    ui->listDisplayBox->setText("List the stadiums chronolocially.");
}
