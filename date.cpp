#include "date.h"

Date Date::converToDate(string str)
{
    string strWords[3];
    short counter = 0;
    for(unsigned long i=0;i<str.length();i++){
        strWords[counter] = str[i];
        if(str[i] == ' '){
            counter++;
        }
    }

    Date date;

    stringstream day_s_str(strWords[1]);
    stringstream year_s_str(strWords[2]);
    date.monthName = strWords[0];
    day_s_str >> date.day;
    year_s_str >> date.year;
    date.month = date.number(monthName);

    return date;

}

bool Date::operator < (const Date& date) const
{
    if(year < date.year)
        return true;
    else if(year == date.year && month < date.month)
        return true;
    else if(year == date.year && month == date.month && day < date.day)
        return true;

    return false;
}

bool Date::operator > (const Date& date) const
{
    if(year > date.year)
        return true;
    else if(year == date.year && month > date.month)
        return true;
    else if(year == date.year && month == date.month && day > date.day)
        return true;

    return false;

}

unsigned Date::number(const string& mn) const
{

    if (mn == "january" || mn == "January")
    {
        return 1;
    }
    else if (mn == "februray" || mn == "February")
    {
        return 2;
    }
    else if (mn == "march" || mn == "March")
    {
        return 3;
    }
    else if (mn == "april" || mn == "April")
    {
        return 4;
    }
    else if (mn == "may" || mn == "May")
    {
        return 5;
    }
    else if (mn == "june" || mn == "June")
    {
        return 6;
    }
    else if (mn == "july" || mn == "July")
    {
        return 7;
    }
    else if (mn == "august" || mn == "August")
    {
        return 8;
    }
    else if (mn == "september" || mn == "September")
    {
        return 9;
    }
    else if (mn == "october" || mn == "October")
    {
        return 10;
    }
    else if (mn == "november" || mn == "November")
    {
        return 11;
    }
    else if (mn == "december" || mn == "December")
    {
        return 12;
    }
    else
    {
        return -1;
    }
}
