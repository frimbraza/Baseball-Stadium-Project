/*
* date header file
* 
* initializes < and > operators, date variables, and print functions
* 
* date
*
*/

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
    Date() : day(0),month(0),year(0),monthName("january"){} //default constructor
    Date(unsigned, unsigned, unsigned);                     //3 parameter constructor
    Date(const string &, unsigned, unsigned);               //3 parameter constructor
    Date addDays(int) const;
    void printNumeric() const;
    void printAlpha() const;
    void converToDate(string s);
    bool operator < (const Date&other) const;
    bool operator > (const Date&) const;
    string getStringDate();
    friend ostream& operator<<(ostream& out, Date& date);


private:
    bool isLeap(unsigned) const;
    unsigned daysPerMonth(unsigned, unsigned y) const;
    string name(unsigned) const;
    unsigned number(const string&) const;
};


#endif // DATE_H
