#include "stadiuminfo.h"

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




























