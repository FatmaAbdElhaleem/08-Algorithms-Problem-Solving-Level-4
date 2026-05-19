#include <iostream>
using namespace std;

// Problem: #17/4
// Write a program to read a Date1, Date2 and make a function to calculate the difference in days.

// Note: Date 1 should be less than Date2

// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Please enter a Day? 25
// Please enter a Month? 3
// Please enter a Year? 2022

// Difference is: 83 Day(s).
// Difference (Including End Day) is: 84 Day(s).

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

bool isDate1BeforeDate2(sDate date1, sDate date2)
{
    return (date1.year < date2.year ? true : (date1.year == date2.year ? ((date1.month == date2.month) ? (date1.day < date2.day) : (date1.month < date2.month)) : false));
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

sDate increaseDateByOneDay(sDate date)
{
    if (isLastDayInMonth(date))
    {
        if (isLastMonthInYear(date.month))
        {
            date.year++;
            date.month = 1;
            date.day = 1;
        }
        else
        {
            date.month++;
            date.day = 1;
        }
    }
    else
        date.day++;
    return date;
}

// solution 1:
int DiffInDays(sDate date1, sDate date2, bool includeEndDay = false)
{
    int diffDays = 0;
    while (isDate1BeforeDate2(date1, date2))
    {
        diffDays++;
        date1 = increaseDateByOneDay(date1);
    }
    return includeEndDay ? ++diffDays : diffDays;
}

// solution 2:
// int numberOfDaysFromBeginningOfYear(const sDate &date)
// {
//     int n = date.day;
//     for (int i = 1; i <= date.month - 1; i++)
//     {
//         n += nOfDaysInMonth(date.year, i);
//     }
//     return n;
// }

// short nOfDaysInYear(short year)
// {
//     return isLeapYear(year) ? 366 : 365;
// }

// int DiffInDays(sDate date1, sDate date2, bool includeEndDay = false)
// {
//     int diffDays = 0;
//     short year;

//     if (!isDate1BeforeDate2(date1, date2))
//         return 0;

//     if (date1.year == date2.year)
//     {
//         diffDays = numberOfDaysFromBeginningOfYear(date2) - numberOfDaysFromBeginningOfYear(date1);
//     }
//     else
//     {
//         diffDays = nOfDaysInYear(date1.year) - numberOfDaysFromBeginningOfYear(date1) + numberOfDaysFromBeginningOfYear(date2);

//         for (year = date1.year + 1; year < date2.year; year++)
//         {
//             diffDays += nOfDaysInYear(year);
//         }
//     }

//     return includeEndDay ? diffDays + 1 : diffDays;
// }

int main()
{
    sDate date1, date2;
    date1 = readDate();
    cout << endl;
    date2 = readDate();

    cout << "Difference is: " << DiffInDays(date1, date2) << " Day(s).\n";
    cout << "Difference (Including End Day) is: " << DiffInDays(date1, date2, true) << " Day(s).\n";
}