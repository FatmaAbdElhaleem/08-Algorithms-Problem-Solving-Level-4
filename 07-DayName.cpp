#include <iostream>
using namespace std;

// Problem: #7/4
// Write a program to read a date, and print the day name of week.

// Please enter a year? 2022
// Please enter a Month? 9
// Please enter a Day? 20

// Date: 20/9/2022
// Day Order: 2
// Day Name: Tue

// Day of Week Calculation Formulas
// Formulas:
// For Gregorian Calendar:
// a= (14-month)/12
// y= year-a
// m= month+12a-2
// d= (day+y+(y/4)-(y/100)+(y/400)+(31m/12)) mod 7

// Day Mapping: 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday

struct sDate
{
    short year;
    short month;
    short day;
};

void readDate(sDate &date)
{
    cout << "Please enter a year? ";
    cin >> date.year;
    cout << "Please enter a Month? ";
    cin >> date.month;
    cout << "Please enter a day? ";
    cin >> date.day;
}

short calcDayOrder(sDate &date)
{
    short a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + 12 * a - 2;
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string getDayName(short d)
{
    string daysArr[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return daysArr[d];
}

int main()
{
    sDate date;
    readDate(date);
    short d = calcDayOrder(date);
    cout << "Date: " << date.day << "/" << date.month << "/" << date.year << endl;
    cout << "Day Order: " << d << endl;
    cout << "Day Name: " << getDayName(d) << endl;
}