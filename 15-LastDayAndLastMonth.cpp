#include <iostream>
using namespace std;

// Problem: #15/4
// Write a program to read a date and check:

// if it is last Day in Month
// If it is last Month In Year

// Please enter a Day? 31
// Please enter a Month? 12
// Please enter a Year? 2022

// Yes, Day is Last Day in Month.
// Yes, Month is Last Month in Year.

struct sDate
{
    short year;
    short month;
    short day;
};

sDate readDate()
{
    sDate date;
    cout << "Please enter a day? ";
    cin >> date.day;
    cout << "Please enter a Month? ";
    cin >> date.month;
    cout << "Please enter a year? ";
    cin >> date.year;
    return date;
}

bool isLeapYear(short year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int nOfDaysInMonth(short year, short month)
{
    const short dayMonthArr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12)
        return 0;
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : dayMonthArr[month - 1];
}

bool isLastDayInMonth(sDate date)
{
    return (date.day == nOfDaysInMonth(date.year, date.month));
}

bool isLastMonthInYear(short month)
{
    return (month == 12);
}

int main()
{
    sDate date;
    date = readDate();
    isLastDayInMonth(date) ? cout << "Yes, Day is Last Day in Month.\n" : cout << "No, Day is not Last Day in Month.\n";
    isLastMonthInYear(date.month) ? cout << "Yes, Month is Last Month in Year.\n" : cout << "No, Month is not Last Month in Year.\n";
}