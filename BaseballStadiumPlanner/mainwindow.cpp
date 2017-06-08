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
    addSouvenirList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//skips hidden 3 characters at beginning of text file
void MainWindow::SkipBOM(std::ifstream &in)         // Added 6/7/2017
{
    char test[3] = {0};
    in.read(test, 3);
    if ((unsigned char)test[0] == 0xEF &&
        (unsigned char)test[1] == 0xBB &&
        (unsigned char)test[2] == 0xBF)
    {
        return;
    }
    in.seekg(0);
}

void MainWindow::addSouvenirList()
{
    ifstream inFile;

    inFile.open("Souvnier.txt");
    if (inFile.fail())
    {
        cout<<"Input Souvnier.txt opening failed.\n";
        exit(1);
    }

    string name;
    double price;
    Souvenir sv;

    while(!inFile.eof())
    {
        std::getline(inFile,name,'\n');
        inFile >> price;
        inFile.ignore(100,'\n');

        sv.setName(name);
        sv.setPrice(price);

        souvenirList.push_back(sv);
    }

    inFile.close();



}

void MainWindow::readFromFile()
{
    ifstream inFile;

    inFile.open("Stadium.txt");
    if (inFile.fail())
    {
        cout<<"Input Stadium.txt opening failed.\n";
        exit(1);
    }
    SkipBOM(inFile);      //skips first 3 weird hidden characters 06/07/2017
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

    // This is where the output is coming from. Take out later
    // stadiumList->displayInOrder();
}
void MainWindow::on_ListButton_clicked()
{
    //ListWindow listWindow;
    //listWindow.setModal(true);
    //listWindow.exec();
    listWindow = new ListWindow(this);
    // listWindow->setAllStadiumsString(stadInfoString);

    vector<StadiumInfo> inOrderList;
    stadiumList->inOrderItemList(inOrderList);
    listWindow->setSortedStadiumList(inOrderList);          // Set sorted List

    BinaryTree<StadiumInfo,CompareByDate> chronoTree;
    for(int i = 0; i < (int)inOrderList.size();++i)
        chronoTree.insertNode(inOrderList[i]);
    vector<StadiumInfo> chronoList;                         // Create chronological vector
    chronoTree.inOrderItemList(chronoList);
    listWindow->setChronoList(chronoList);

    //everything between these lines-->added 06/07/2017----
    BinaryTree<StadiumInfo,CompareByStadiumName> stadiumNameTree;
    for(int i = 0; i < (int)inOrderList.size();++i)
        stadiumNameTree.insertNode((inOrderList[i]));
    vector<StadiumInfo> sortedNameList;
    stadiumNameTree.inOrderItemList(sortedNameList);
    listWindow->setStadiumNameSortedList(sortedNameList);
    //end of lines----------------------------------------

    listWindow->setModal(true);
    listWindow->show();
}

// 6/8/2017!!!!!!!!!!!!!!!!!!!!!!!!!!
void MainWindow::on_TripsButton_clicked()
{
    tripWindow = new TripWindow(this);

    vector<StadiumInfo> tempVector;
    stadiumList->inOrderItemList(tempVector);

    vector<StadiumInfo> sortedNameList;
    BinaryTree<StadiumInfo,CompareByStadiumName> nameTree;
    for(int i = 0; i < (int)tempVector.size();++i)
        nameTree.insertNode(tempVector[i]);

    nameTree.inOrderItemList(sortedNameList);

    tripWindow->setSortedStadList(sortedNameList);

    tripWindow->setSouvList(this->souvenirList);   // 6/8/2017

    tripWindow->setModal(true);
    tripWindow->exec();
}

void MainWindow::on_AdminButton_clicked()
{
    AdminLogin = new adminLogin(this);
    AdminLogin->setModal(true);
    AdminLogin->show();

}


void MainWindow::on_UpdateButton_clicked()
{
    delete stadiumList;
    stadiumList = new BinaryTree<StadiumInfo,StadiumComparebyTeam>();

    ifstream inFile;

    inFile.open("NewStadium.txt");
    if (inFile.fail())
    {
        cout<<"Input NewStadium.txt opening failed.\n";
        exit(1);
    }

    string stadiumName,team,street,cityInfo,phoneNum,capacity,openedDate,NL,grass;
    StadiumInfo stadium;

    while(!inFile.eof())
    {
        std::getline(inFile,stadiumName,'\n');
        std::getline(inFile,team,'\n');
        std::getline(inFile,street,'\n');
        std::getline(inFile,cityInfo,'\n');
        std::getline(inFile,phoneNum,'\n');
        std::getline(inFile,openedDate,'\n');
        std::getline(inFile,capacity,'\n');
        std::getline(inFile,NL,'\n');
        std::getline(inFile,grass,'\n');

        // Putting here to test. Remove the code after this comment
        stadInfoString += stadiumName + "\n" + team + "\n" + street +"\n";
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

        stadium.setName(stadiumName);
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







    souvenirList.clear();

    inFile.open("NewSouvnier.txt");
    if (inFile.fail())
    {
        cout<<"Input NewSouvnier.txt opening failed.\n";
        exit(1);
    }

    string name;
    double price;
    Souvenir sv;

    while(!inFile.eof())
    {
        std::getline(inFile,name,'\n');
        inFile >> price;
        inFile.ignore(100,'\n');

        sv.setName(name);
        sv.setPrice(price);

        souvenirList.push_back(sv);
    }

    inFile.close();

}
