#include <iostream>
using namespace std;

// Problem: #10/4
// Write a program to print total days from the beginning of year.

// Please enter a Day? 20
// Please enter a Month? 9
// Please enter a Year? 2022

// Number of Days from the beginning of the year is 263

struct sDate
{
    short year;
    short month;
    short day;
};

void readDate(sDate &date)
{
    cout << "Please enter a day? ";
    cin >> date.day;
    cout << "Please enter a Month? ";
    cin >> date.month;
    cout << "Please enter a year? ";
    cin >> date.year;
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

int numberOfDaysFromBeginningOfYear(const sDate &date)
{
    int n = date.day;
    for (int i = 1; i <= date.month - 1; i++)
    {
        n += nOfDaysInMonth(date.year, i);
    }
    return n;
}

int main()
{
    sDate date;
    readDate(date);
    printf("Number of Days from the beginning of the year is %d", numberOfDaysFromBeginningOfYear(date));
}