#include "date.h"
#include <string>

void Date::converToDate(string str)
{
    string str1, str2, str3;
    int pos;

    pos = str.find(' ', 0);

    str1 = str.substr(0,pos);
    monthName = str1;
    str2 = str.substr(str1.length()+1,2);
    str3 = str.substr(str1.length()+str2.length()+2,4);

    stringstream day_s_str(str2);
    stringstream year_s_str(str3);
    day_s_str >> day;
    year_s_str >> year;
    month = number(monthName);


}

ostream& operator<<(ostream& out, Date& date)
{
    out << date.month <<" " << date.day <<" " << date.year <<" ";

    return out;

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

int Date::number(const string& mn) const
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
