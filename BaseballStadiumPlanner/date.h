#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
private:
    unsigned day;
    unsigned month;
    unsigned year;
    string monthName;

public:
    Date() : day(0),month(0),year(0),monthName("january"){}
    Date(unsigned, unsigned, unsigned);
    Date(const string &, unsigned, unsigned);
    Date addDays(int) const;
    void printNumeric() const;
    void printAlpha() const;
    void converToDate(string s);
    bool operator < (const Date&) const;
    bool operator > (const Date&) const;
    string getStringDate();
    friend ostream& operator<<(ostream& out, Date& date);


private:
    bool isLeap(unsigned) const;
    unsigned daysPerMonth(unsigned, unsigned y) const;
    string name(unsigned) const;
    unsigned number(const string&) const;
};



//ostream& operator<<(ostream& out, Date& date)
//{
//    out << date.monthName <<" " << date.day <<" " << date.year <<" ";

//    return out;

//}




//Date Date::converToDate(string str)
//{
//    string strWords[3];
//    short counter = 0;
//    for(unsigned long i=0;i<str.length();i++){
//        strWords[counter] = str[i];
//        if(str[i] == ' '){
//            counter++;
//        }
//    }

//    Date date;

//    stringstream day_s_str(strWords[1]);
//    stringstream year_s_str(strWords[2]);
//    date.monthName = strWords[0];
//    day_s_str >> date.day;
//    year_s_str >> date.year;
//    date.month = date.number(monthName);

//    return date;

//}

//bool Date::operator < (const Date& date) const
//{
//    if(year < date.year)
//        return true;
//    else if(year == date.year && month < date.month)
//        return true;
//    else if(year == date.year && month == date.month && day < date.day)
//        return true;

//    return false;
//}

//bool Date::operator > (const Date& date) const
//{
//    if(year > date.year)
//        return true;
//    else if(year == date.year && month > date.month)
//        return true;
//    else if(year == date.year && month == date.month && day > date.day)
//        return true;

//    return false;

//}

//unsigned Date::number(const string& mn) const
//{

//    if (mn == "january" || mn == "January")
//    {
//        return 1;
//    }
//    else if (mn == "februray" || mn == "February")
//    {
//        return 2;
//    }
//    else if (mn == "march" || mn == "March")
//    {
//        return 3;
//    }
//    else if (mn == "april" || mn == "April")
//    {
//        return 4;
//    }
//    else if (mn == "may" || mn == "May")
//    {
//        return 5;
//    }
//    else if (mn == "june" || mn == "June")
//    {
//        return 6;
//    }
//    else if (mn == "july" || mn == "July")
//    {
//        return 7;
//    }
//    else if (mn == "august" || mn == "August")
//    {
//        return 8;
//    }
//    else if (mn == "september" || mn == "September")
//    {
//        return 9;
//    }
//    else if (mn == "october" || mn == "October")
//    {
//        return 10;
//    }
//    else if (mn == "november" || mn == "November")
//    {
//        return 11;
//    }
//    else if (mn == "december" || mn == "December")
//    {
//        return 12;
//    }
//    else
//    {
//        return -1;
//    }
//}




#endif // DATE_H
