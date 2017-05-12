#ifndef STADIUMINFO_H
#define STADIUMINFO_H

#include "date.h"


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
    Date getOpened();
    bool hasGrass();
    bool isNL();

};


#endif // STADIUMINFO_H
