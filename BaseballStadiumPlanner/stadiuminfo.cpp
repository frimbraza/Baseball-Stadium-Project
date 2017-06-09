/*
* StadiumInfo class file
* 
* contains stadium variables, set/get functions, = and << operators
* 
*/

#include "stadiuminfo.h"

//stadiuminfo class
//Big O: O(n)
StadiumInfo::StadiumInfo()
    :opened()
{
    name = "NoName";
    team = "NoTeam";
    street = "NoStreet";
    cityInfo = "NoCity";
    phoneNumber = "NoNumber";
    capacity = 0;
    grass = false;
    NL = false;
}

//Big O: O(1)
void StadiumInfo::setName(string newName)
{
    name = newName;
}

//Big O: O(1)
void StadiumInfo::setTeam(string newTeam)
{
    team = newTeam;
}

//Big O: O(1)
void StadiumInfo::setStreet(string newStreet)
{
    street = newStreet;
}

//Big O: O(1)
void StadiumInfo::setCityInfo(string newCity)
{
    cityInfo = newCity;
}

//Big O: O(1)
void StadiumInfo::setPhone(string newPhone)
{
    phoneNumber = newPhone;
}

//Big O: O(1)
void StadiumInfo::setCap(int newCap)
{
    capacity = newCap;
}

//Big O: O(1)
void StadiumInfo::setOpened(Date newOpen)
{
    opened = newOpen;
}

//Big O: O(1)
void StadiumInfo::setHasGrass(bool newHasGrass)
{
    grass = newHasGrass;
}

//Big O: O(1)
void StadiumInfo::setIsNL(bool newIsNL)
{
    NL = newIsNL;
}

//Big O: O(1)
string StadiumInfo::getName()
{
    return name;
}

//Big O: O(1)
string StadiumInfo::getTeam()
{
    return team;
}

//Big O: O(1)
string StadiumInfo::getStreet()
{
    return street;
}

//Big O: O(1)
string StadiumInfo::getCityInfo()
{
    return cityInfo;
}

//Big O: O(1)
string StadiumInfo::getPhone()
{
    return phoneNumber;
}

//Big O: O(1)
int StadiumInfo::getCapacity()
{
    return capacity;
}

//Big O: O(1)
Date StadiumInfo::getOpened()
{
    return opened;
}

//Big O: O(1)
bool StadiumInfo::hasGrass()
{
    return grass;
}

//checks if a stadium is an NL stadium
//Big O: O(1)
bool StadiumInfo::isNL()
{
    return NL;
}

//<< operator
ostream& operator<<(ostream& out, StadiumInfo& stadium)
{
    out << stadium.name << "\n" << stadium.team << "\n" << stadium.street << "\n"
        << stadium.cityInfo << "\n" <<stadium.phoneNumber << "\n" << stadium.opened << "\n"
        << stadium.capacity << "\n";
    if (stadium.NL)
        out << "NL\n";
    else
        out << "AL\n";
    if (stadium.grass)
        out << "grass\n";
    else
        out << "no grass\n";
    return out;
}

// = operator
void StadiumInfo::operator=(StadiumInfo other)
{
    name = other.name;
    team = other.team;
    street = other.street;
    cityInfo = other.cityInfo;
    phoneNumber = other.phoneNumber;
    capacity = other.capacity;
    opened = other.opened;
    grass = other.grass;
    NL = other.NL;
}




























