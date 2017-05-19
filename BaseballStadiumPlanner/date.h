#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>

using namespace std;

class Date
{
public:
    Date():day(1),month(1),year(2000),monthName("Jan"){}
    Date(int, int, int);
    Date(const string &, int, int);
    Date addDays(int) const;
    void printNumeric() const;
    void printAlpha() const;
    void converToDate(string s);
    bool operator < (const Date&) const;
    bool operator > (const Date&) const;
    friend ostream& operator<<(ostream& out, Date& date);

private:
    int day;
    int month;
    int year;
    string monthName;

    bool isLeap(int) const;
    int daysPerMonth(int, int y) const;
    string name(int) const;
    int number(const string&) const;
};




#endif // DATE_H
