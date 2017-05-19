#include "stadiuminfo.h"

StadiumInfo::StadiumInfo()
{

}

void StadiumInfo::setName(string newName)
{
    name = newName;
}

void StadiumInfo::setTeam(string newTeam)
{
    team = newTeam;
}

void StadiumInfo::setStreet(string newStreet)
{
    street = newStreet;
}

void StadiumInfo::setCityInfo(string newCity)
{
    cityInfo = newCity;
}

void StadiumInfo::setPhone(string newPhone)
{
    phoneNumber = newPhone;
}

void StadiumInfo::setCap(int newCap)
{
    capacity = newCap;
}

void StadiumInfo::setOpened(Date newOpen)
{
    opened = newOpen;
}

void StadiumInfo::setHasGrass(bool newHasGrass)
{
    grass = newHasGrass;
}

void StadiumInfo::setIsNL(bool newIsNL)
{
    NL = newIsNL;
}

string StadiumInfo::getName()
{
    return name;
}

string StadiumInfo::getTeam()
{
    return team;
}

string StadiumInfo::getStreet()
{
    return street;
}

string StadiumInfo::getCityInfo()
{
    return cityInfo;
}

string StadiumInfo::getPhone()
{
    return phoneNumber;
}

int StadiumInfo::getCapacity()
{
    return capacity;
}

Date StadiumInfo::getOpened()
{
    return opened;
}

bool StadiumInfo::hasGrass()
{
    return grass;
}

bool StadiumInfo::isNL()
{
    return NL;
}

ostream& operator<<(ostream& out, StadiumInfo& stadium)
{
    out << stadium.name << endl << stadium.team << endl << stadium.street << endl
        << stadium.cityInfo << endl <<stadium.phoneNumber <<endl << stadium.opened << endl
        << stadium.capacity;

    return out;
}





























