#ifndef STADIUMINFO_H
#define STADIUMINFO_H

#include "date.h"
#include <iostream> // for testing, remove in the final draft

using namespace std; // for testing, remove (maybe keep) in the final draft

class StadiumInfo
{
private:
    // Info gathered in the docs
    string name;
    string team;
    string street;
    string cityInfo;
    string phoneNumber;
    int capacity;

    // Info outside file
    Date opened;
    bool grass;
    bool NL;

public:
    StadiumInfo();

    void setName(string newName);
    void setTeam(string newTeam);
    void setStreet(string newStreet);
    void setCityInfo(string newCity);
    void setPhone(string newPhone);
    void setCap(int newCap);
    void setOpened(Date newOpen);
    void setHasGrass(bool newHasGrass);
    void setIsNL(bool newIsNL);

    string getName();
    string getTeam();
    string getStreet();
    string getCityInfo();
    string getPhone();
    int getCapacity();
    string getOpened();
    bool hasGrass();
    bool isNL();

    friend ostream& operator<<(ostream& out, StadiumInfo& stadium);

    void operator=(StadiumInfo other);
};


#endif // STADIUMINFO_H
