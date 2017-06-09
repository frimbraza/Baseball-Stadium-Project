#include "adminfuntion.h"
#include "ui_adminfuntion.h"
#include <QMessageBox>

adminFuntion::adminFuntion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminFuntion)
{
    ui->setupUi(this);
    stadiumList = new BinaryTree<StadiumInfo,StadiumComparebyTeamName>();

    readFromFile();
    addSouvenirList();

}

adminFuntion::~adminFuntion()
{
    delete ui;
}

//Loading info to stadium list and souvenir list
void adminFuntion::readFromFile()
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

    vector<StadiumInfo> inOrderList;
    stadiumList->inOrderItemList(inOrderList);
    setSortedStadiumList(inOrderList);          // Set sorted List



}

void adminFuntion::setSortedStadiumList(const vector<StadiumInfo>& otherList)
{
    this->sortedList = otherList;
}

void adminFuntion::addSouvenirList()
{
    ifstream inFile;

    inFile.open("Souvnier.txt");
    if (inFile.fail())
    {
        cout<<"Input file opening failed.\n";
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


//Save changes to new file
void adminFuntion::saveAtNewSouvnierFile()
{
    ofstream outFile;
    outFile.open("NewSouvnier.txt");
    if (outFile.fail())
    {
        cout <<"Output file opening failed.\n"
           <<"New file created.\n";
        exit(1);
    }

    for(int i=0; i<(int)souvenirList.size();i++)
    {
        outFile << souvenirList[i].getName() <<endl
                << souvenirList[i].getPrice();
        if(i <(int)souvenirList.size()-1)
            outFile << "\n";
    }

}

void adminFuntion::saveAtNewStadiumFile()
{
    ofstream outFile;
    outFile.open("NewStadium.txt");
    if (outFile.fail())
    {
        cout <<"Output file opening failed.\n"
           <<"New file created.\n";
        exit(1);
    }

    for(int i=0; i<(int)sortedList.size();i++)
    {
        outFile << sortedList[i].getName() <<endl
                << sortedList[i].getTeam() <<endl
                << sortedList[i].getStreet() <<endl
                << sortedList[i].getCityInfo() <<endl
                << sortedList[i].getPhone() <<endl
                << sortedList[i].getOpened().getStringDate() <<endl
                << sortedList[i].getCapacity()<<endl;

        if(sortedList[i].isNL())
            outFile << "NL\n";
        else
            outFile << "AL\n";

        if(sortedList[i].hasGrass())
            outFile << "grass";
        else
            outFile << "no grass";
        if(i <(int)sortedList.size()-1)
            outFile << "\n";
    }

}


//Display button
void adminFuntion::on_Display_clicked()
{
    displaySouvenir();
}

void adminFuntion::on_Display_Stadium_List_1_clicked()
{
    printAll();
}

void adminFuntion::on_Display_Stadium_List_clicked()
{
    printAll();
}


//Inner display
void adminFuntion::displaySouvenir()
{
    initializeSouvenirTableInfo();

    for(int i=0; i<(int)souvenirList.size(); i++)
        appendSouvenir(i,souvenirList);

}

void adminFuntion::printAll()
{
    initializeStadiumTableInfo();

    for(int i = 0; i < (int)sortedList.size();++i)
    {
        appendStadium(i, sortedList);
    }
}


//Append table
void adminFuntion::appendSouvenir(int index, vector<Souvenir> theList)
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    int n = ui->tableWidget->rowCount()-1;



    ui->tableWidget->setItem(n,0,new QTableWidgetItem(QString::fromStdString(theList[index].getName())));
    ui->tableWidget->setItem(n,1,new QTableWidgetItem(QString::fromStdString(theList[index].getPrice())));

}

void adminFuntion::appendStadium(int index, vector<StadiumInfo> theList)
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    int n = ui->tableWidget->rowCount()-1;

    ui->tableWidget->setItem(n,0,new QTableWidgetItem(QString::fromStdString(theList[index].getName())));
    ui->tableWidget->setItem(n,1,new QTableWidgetItem(QString::fromStdString(theList[index].getTeam())));
    ui->tableWidget->setItem(n,2,new QTableWidgetItem(QString::fromStdString(theList[index].getCityInfo())));
    ui->tableWidget->setItem(n,3,new QTableWidgetItem(QString::fromStdString(theList[index].getOpened().getStringDate())));
    ui->tableWidget->setItem(n,4,new QTableWidgetItem(QString::fromStdString(to_string(theList[index].getCapacity()))));

    if(theList[index].hasGrass())
        ui->tableWidget->setItem(n,5,new QTableWidgetItem(QString::fromStdString("grass")));
    else
        ui->tableWidget->setItem(n,5,new QTableWidgetItem(QString::fromStdString("No grass")));

    if(theList[index].isNL())
        ui->tableWidget->setItem(n,6,new QTableWidgetItem(QString::fromStdString("National League")));
    else
        ui->tableWidget->setItem(n,6,new QTableWidgetItem(QString::fromStdString("American League")));

}

//Initialize table info
void adminFuntion::initializeSouvenirTableInfo()
{
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(1,150);

    std::string labels = "Name, Price";
    ui->tableWidget->setHorizontalHeaderLabels(QString::fromStdString(labels).split(","));

    ui->tableWidget->setRowCount(0);
}

void adminFuntion::initializeStadiumTableInfo()
{
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setColumnWidth(1,150);

    std::string labels = "Stadium, Team, Address, Date Opened, Capacity, Grass, Type";
    ui->tableWidget->setHorizontalHeaderLabels(QString::fromStdString(labels).split(","));

    ui->tableWidget->setRowCount(0);
}

//Souvenir Functions
void adminFuntion::on_Add_Souvenir_clicked()
{
    QString name, price;
    double priceNum;

    name = ui->lineEdit_AddName->text();
    price = ui->lineEdit_AddPrice->text();

    if((price.toStdString().size() == 0) || (name.toStdString().size() == 0))
    {
        QMessageBox msgBox;

        msgBox.setText("Something is empty");
        msgBox.exec();

        return;

    }
    for(int i = 0; i < (int)price.toStdString().size(); ++i)
    {
        if(!isdigit(price.toStdString()[i]))
        {
            QMessageBox msgBox;

            msgBox.setText("Price should be a number");
            msgBox.exec();

            return;

        }
    }

    priceNum = stod(price.toStdString());

    Souvenir sv;
    sv.setName(name.toStdString());
    sv.setPrice(priceNum);

    souvenirList.push_back(sv);

    saveAtNewSouvnierFile();

    displaySouvenir();


}

void adminFuntion::on_Delete_Souvenir_clicked()
{
    QString name;
    bool exist = false;

    name = ui->lineEdit_deleteName->text();

    for (int i=0; i<(int)souvenirList.size(); i++)
    {
        if(souvenirList[i].getName() == name.toStdString())
        {
            souvenirList.erase(souvenirList.begin()+ i);
            exist = true;
        }

    }

    if(!exist)
    {
        QMessageBox msgBox;

        msgBox.setText("This Souvenir is not exist");
        msgBox.exec();

        return;
    }



    saveAtNewSouvnierFile();

    displaySouvenir();
}

void adminFuntion::on_Change_Souvenir_clicked()
{
    QString name, price;
    double priceNum;
    bool exist = false;

    name = ui->lineEdit_ChangeName->text();
    price = ui->lineEdit_ChangePrice->text();

    if((price.toStdString().size() == 0) || (name.toStdString().size() == 0))
    {
        QMessageBox msgBox;

        msgBox.setText("Something is empty");
        msgBox.exec();

        return;

    }
    for(int i = 0; i < (int)price.toStdString().size(); ++i)
    {
        if(!isdigit(price.toStdString()[i]))
        {
            QMessageBox msgBox;

            msgBox.setText("Price should be a number");
            msgBox.exec();

            return;

        }
    }

    priceNum = stod(price.toStdString());

    for (int i=0; i<(int)souvenirList.size(); i++)
    {
        if(souvenirList[i].getName() == name.toStdString())
        {
            souvenirList[i].setPrice(priceNum);
            exist = true;
        }
    }

    if(!exist)
    {
        QMessageBox msgBox;

        msgBox.setText("This Souvenir is not exist");
        msgBox.exec();

        return;
    }




    saveAtNewSouvnierFile();

    displaySouvenir();

}

//New Team Function
void adminFuntion::on_AddNewTeam_clicked()
{
    QString team, stadium;
    bool teamExist = false, stadiumExist = false;


    team = ui->lineEdit_TeamSwitch->text();
    stadium = ui->lineEdit_StadiumSwitch->text();

    string tempTeam;
    string tempStadium;

    for(int i=0; i < (int)sortedList.size();i++)
    {
        if(sortedList[i].getTeam() == team.toStdString())
        {
            tempStadium = sortedList[i].getName();
            teamExist = true;
        }
    }

    for(int i=0; i<(int)sortedList.size();i++)
    {
        if(sortedList[i].getName() == stadium.toStdString())
        {
            tempTeam = sortedList[i].getTeam();
            sortedList[i].setTeam(team.toStdString());
            stadiumExist = true;
        }
    }

    for(int i=0; i<(int)sortedList.size();i++)
    {
        if(sortedList[i].getName() == tempStadium)
            sortedList[i].setTeam(tempTeam);
    }


    QMessageBox msgBox;

    if(!teamExist)
    {
        msgBox.setText("This team is not exist");
        msgBox.exec();

        return;
    }
    else if(!stadiumExist)
    {
        msgBox.setText("This stadium is not exist");
        msgBox.exec();

        return;
    }


    printAll();
    saveAtNewStadiumFile();

}



void adminFuntion::on_AddNewStadium_clicked()
{
    std::string stadiumName, teamName, street,
            cityInfo, phoneNum, capacity;

    bool grass, type;

    stadiumName = ui->lineEdit_NewStadium->text().toStdString();
    teamName = ui->lineEdit_NewTeam->text().toStdString();
    street = ui->lineEdit_Street->text().toStdString();
    cityInfo = ui->lineEdit_CityInfo->text().toStdString();
    phoneNum = ui->lineEdit_PhoneNum->text().toStdString();
    capacity = ui->lineEdit_Capacity->text().toStdString();

    if(ui->noGrass->isChecked())
        grass = false;
    else if(ui->haveGrass->isChecked())
        grass = true;
    else
        grass = false;

    if(ui->AL->isChecked())
        type = false;
    else if(ui->NL->isChecked())
        type = true;
    else
        type = false;

    string month, day, openDate, year;
    month = ui->comboBox_Month->currentText().toStdString();
    day = ui->comboBox_Day->currentText().toStdString();
    year = ui->lineEdit_Year->text().toStdString();



    if((stadiumName.size() == 0) || (teamName.size() == 0)
            ||(street.size() == 0)||(cityInfo.size() == 0)
            ||(phoneNum.size() == 0)||(year.size() == 0)||(capacity.size() == 0))
    {
        QMessageBox msgBox;

        msgBox.setText("Something is empty");
        msgBox.exec();

        return;

    }

    for(int i = 0; i < (int)capacity.size();++i)
    {
        if(!isdigit(capacity[i]))
        {
            QMessageBox msgBox;

            msgBox.setText("Capacity should be a number");
            msgBox.exec();


            return;
        }
    }

    for(int i =0; i < (int)year.size();++i)
    {
        if(!isdigit(year[i]))
        {
            QMessageBox msgBox;

            msgBox.setText("Year should be a number");
            msgBox.exec();

            return;
        }
    }
    openDate = month + " " + day + " " + year;

    Date date;
    date.converToDate(openDate);


    StadiumInfo newStadium;

    newStadium.setName(stadiumName);
    newStadium.setTeam(teamName);
    newStadium.setStreet(street);
    newStadium.setCityInfo(cityInfo);
    newStadium.setPhone(phoneNum);
    newStadium.setCap(stoi(capacity));
    newStadium.setOpened(date);
    newStadium.setHasGrass(grass);
    newStadium.setIsNL(type);

    sortedList.push_back(newStadium);

    printAll();
    saveAtNewStadiumFile();


}


