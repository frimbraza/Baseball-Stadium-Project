#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>

using namespace std;

class Date
{
private:
    unsigned day;
    unsigned month;
    unsigned year;
    string monthName;

public:
    Date(){}
    Date(unsigned, unsigned, unsigned);
    Date(const string &, unsigned, unsigned);
    Date addDays(int) const;
    void printNumeric() const;
    void printAlpha() const;
    Date converToDate(string s);
    bool operator < (const Date&) const;
    bool operator > (const Date&) const;
private:
    bool isLeap(unsigned) const;
    unsigned daysPerMonth(unsigned, unsigned y) const;
    string name(unsigned) const;
    unsigned number(const string&) const;
};

#endif // DATE_H
