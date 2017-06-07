#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listwindow.h"
#include "tripwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stadiumList = new BinaryTree<StadiumInfo,StadiumComparebyTeam>();
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

    string name, team,street,cityInfo,phoneNum,capacity,openedDate,NL,grass;
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
        std::getline(inFile,grass,'\n');

        // Putting here to test. Remove the code after this comment
        stadInfoString += name + "\n" + team + "\n" + street +"\n";
        stadInfoString += cityInfo + "\n" + phoneNum + "\n" + openedDate +"\n";
        stadInfoString += capacity + "\n" + NL + "\n\n";
        // End of test, please remove the code between these comments

        stringstream cap_s_str(capacity);
        // int cap = stoi(capacity);
        int cap;
        cap_s_str >> cap;

        Date date;
        date.converToDate(openedDate);

        // cout << "Date:" << date << endl; // COUT the date, for testing
        bool isNL;
        if(NL == "NL")
            isNL = true;
        else
            isNL = false;

        // grass string to bool
        if(grass == "grass")
            stadium.setHasGrass(true);
        else
            stadium.setHasGrass(false);

        stadium.setName(name);
        stadium.setTeam(team);
        stadium.setStreet(street);
        stadium.setCityInfo(cityInfo);
        stadium.setPhone(phoneNum);
        stadium.setCap(cap);
        stadium.setOpened(date);
        stadium.setIsNL(isNL);

        stadiumList->insertNode(stadium);
        //list->insertNode(stadium);
        // cout << stadium << endl; // Add this to COUT stadium info for testing
    }

    inFile.close();

    stadiumList->displayInOrder();  // This is where the output is coming from. Take out later
}

void MainWindow::on_ListButton_clicked()
{
    //ListWindow listWindow;
    //listWindow.setModal(true);
    //listWindow.exec();
    listWindow = new ListWindow(this);
    listWindow->setAllStadiumsString(stadInfoString);

    vector<StadiumInfo> inOrderList;
    stadiumList->inOrderItemList(inOrderList);
    listWindow->setSortedStadiumList(inOrderList);          // Set sorted List

    BinaryTree<StadiumInfo,CompareByDate> chronoTree;
    for(int i = 0; i < inOrderList.size();++i)
        chronoTree.insertNode(inOrderList[i]);
    vector<StadiumInfo> chronoList;                         // Create chronological vector
    chronoTree.inOrderItemList(chronoList);
    listWindow->setChronoList(chronoList);


    listWindow->setModal(true);
    listWindow->show();
}

void MainWindow::on_TripsButton_clicked()
{
    TripWindow tripWindow;
    tripWindow.setModal(true);
    tripWindow.exec();
}

void MainWindow::on_AdminButton_clicked()
{
    AdminLogin = new adminLogin(this);
    AdminLogin->setModal(true);
    AdminLogin->show();
}
