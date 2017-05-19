#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFromFile()
{
    ifstream inFile;

    inFile.open("Stadium.txt");
    if (inFile.fail())
    {
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    string name, team,street,cityInfo,phoneNum,capacity,openedDate,NL;
    StadiumInfo stadium;

    while(!inFile.eof())
    {
        std::getline(inFile,name,'\n');
        std::getline(inFile,team,'\n');
        std::getline(inFile,street,'\n');
        std::getline(inFile,cityInfo,'\n');
        std::getline(inFile,phoneNum,'\n');
        std::getline(inFile,openedDate,'\n');
        std::getline(inFile,capacity,'\n');
        std::getline(inFile,NL,'\n');

        // stringstream cap_s_str(capacity);
        int cap = stoi(capacity);
        // cap_s_str >> cap;

        Date date;
        date.converToDate(openedDate);

        cout << "Date:" << date << endl;
        bool isNL;
        if(NL == "NL")
            isNL = true;
        else
            isNL = false;

        stadium.setName(name);
        stadium.setTeam(team);
        stadium.setStreet(street);
        stadium.setCityInfo(cityInfo);
        stadium.setPhone(phoneNum);
        stadium.setCap(cap);
        stadium.setOpened(date);
        stadium.setIsNL(isNL);

        // list->insertNode(stadium);
        cout << stadium << endl;
    }

    inFile.close();


}

void MainWindow::on_ListButton_clicked()
{

}
