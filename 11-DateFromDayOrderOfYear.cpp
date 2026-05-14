#include <iostream>
using namespace std;

// Problem: #11/4
// Write a program to print total days from the beginning of year, then

// Take the total days and convert them back to date.

// Please enter a Day? 20
// Please enter a Month? 9
// Please enter a Year? 2022

// Number of Days from the beginning of the year is 263
// Date for [263] is: 20/9/2022

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

sDate getDateFromDayOrderInYear(short year, int nOfDays)
{
    sDate date;
    int remainingDays = nOfDays;
    short monthDays = 0;
    date.year = year;
    date.month = 1;
    while (remainingDays > 0)
    {
        monthDays = nOfDaysInMonth(year, date.month);

        if (remainingDays > monthDays)
        {
            remainingDays -= monthDays;
            date.month++;
        }

        else
        {
            date.day = remainingDays;
            break;
        }
    }
    return date;
}

int main()
{
    sDate userDate;
    sDate date;
    readDate(userDate);
    int nOfDays(numberOfDaysFromBeginningOfYear(userDate));
    printf("Number of Days from the beginning of the year is %d\n", nOfDays);
    date = getDateFromDayOrderInYear(userDate.year, nOfDays);
    printf("Date for [%d] is: %d/%d/%d\n", nOfDays, date.day, date.month, date.year);
}