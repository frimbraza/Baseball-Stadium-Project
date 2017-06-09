/*
* date class file
* 
* contains <, <<, and > operators, date variables, and print functions
* 
* 
*
*/

#include "date.h"

//convert string to date
//O(n)
void Date::converToDate(string str)
{
    string strWords[3];
    short counter = 0;
    for(unsigned long i=0;i<str.length();i++){
        if(str[i] == ' '){
            counter++;
        }
        else if(str[i] == ',')
        {
        }
        else
        {
            strWords[counter] += str[i];
        }

    }

    stringstream day_s_str(strWords[1]);
    stringstream year_s_str(strWords[2]);
    monthName = strWords[0];
    day_s_str >> day;
    year_s_str >> year;
    month = number(monthName);
}

//get date in string
//O(1)
string Date::getStringDate()
{
    string dateHolder = "";
    dateHolder += monthName;
    dateHolder += " ";
    dateHolder += to_string(day);
    dateHolder += ", ";
    dateHolder += to_string(year);
    return dateHolder;
}

//<< operator
//O(1)
ostream& operator<<(ostream& out, Date& date)
{
    out << date.monthName <<" " << date.day <<" " << date.year <<" ";

    return out;

}

//< operator
//O(1)
bool Date::operator < (const Date& other) const
{
    if(year > other.year)
        return false;
    else if(year < other.year)
        return true;
    else if(month > other.month)
        return false;
    else if(month < other.month)
        return true;
    else if(day > other.day)
        return false;
    else
        return true;
}

// > operator
//O(1)
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

//unsigned number string; assign months to numbers
//O(1)
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
