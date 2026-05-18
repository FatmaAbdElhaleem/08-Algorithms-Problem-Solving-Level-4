#include <iostream>
using namespace std;

// Problem: #12/4
// Write a program to read date and read how many days to add to it, print the results on screen

// Please enter a Day? 10
// Please enter a Month? 10
// Please enter a Year? 2022
// How many days to add? 2500
// Date after adding [2500] days is: 14/8/2029

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

short readDaysToAdd()
{
    short daysToAdd;
    cout << "How many days to add? ";
    cin >> daysToAdd;
    return daysToAdd;
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

// solution 1:

// sDate addDaysToDate(sDate userDate, int daysToAdd)
// {
//     int day = daysToAdd + userDate.day;
//     short daysInMonth;
//     while (true)
//     {
//         daysInMonth = nOfDaysInMonth(userDate.year, userDate.month);
//         if (day > daysInMonth)
//         {
//             userDate.month++;
//             day -= daysInMonth;
//             if (userDate.month > 12)
//             {
//                 userDate.year++;
//                 userDate.month = 1;
//             }
//         }
//         else
//         {
//             userDate.day = day;
//             break;
//         }
//     }
//     return userDate;
// }

// solution 2:

short nOfDaysInYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}

sDate addDaysToDate(sDate userDate, int daysToAdd)
{
    short yearDays;
    int remainingDays = numberOfDaysFromBeginningOfYear(userDate) + daysToAdd;
    sDate newDate;
    newDate.year = userDate.year;
    newDate.month = 1;

    while (true)
    {
        yearDays = nOfDaysInYear(newDate.year);
        if (remainingDays > yearDays)
        {
            remainingDays -= yearDays;
            newDate.year++;
        }
        else if (remainingDays > nOfDaysInMonth(newDate.year, newDate.month))
        {
            remainingDays -= nOfDaysInMonth(newDate.year, newDate.month);
            newDate.month++;
            // if (newDate.month > 12)
            // {
            //     newDate.month = 1;
            //     newDate.year++;
            // }
        }
        else
        {
            newDate.day = remainingDays;
            break;
        }
    }
    return newDate;
}

int main()
{
    sDate userDate, dateAfterAdding;
    readDate(userDate);
    int daysToAdd = readDaysToAdd();
    dateAfterAdding = addDaysToDate(userDate, daysToAdd);
    cout << "Date after adding [" << daysToAdd << "] days is:" << dateAfterAdding.day << "/" << dateAfterAdding.month << "/" << dateAfterAdding.year;
}