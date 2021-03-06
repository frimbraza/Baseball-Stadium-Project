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
