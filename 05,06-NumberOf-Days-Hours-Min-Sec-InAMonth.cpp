#include <iostream>
using namespace std;

// Problem: #5/4
// Write a program to print Number of:
// Days Hours Minutes Seconds in a certain Month.

// Please enter a Year to check? 2000
// Please enter a Month to check? 2
// Number of Days in Month [2] is 29
// Number of Hours in Month [2] is 696
// Number of Minutes in Month [2] is 41760
// Number of Seconds in Month [2] is 2505600

// Please enter a Year to check? 1971
// Please enter a Month to check? 2
// Number of Days in Month [2] is 28
// Number of Hours in Month [2] is 672
// Number of Minutes in Month [2] is 40320
// Number of Seconds in Month [2] is 2419200

// Problem: #6/4
// simplify the nOfDaysInMonth function into 4 lines.

short readShortVar(string name)
{
    short number;
    cout << "Please enter a " << name << " to check? ";
    cin >> number;
    return number;
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

    // problem 5
    // short monthArr[7] = {1, 3, 5, 7, 8, 10, 12};
    // for (int i = 0; i < 7; i++)
    // {
    //     if (month == monthArr[i])
    //         return 31;
    // }

    // if (month == 2)
    //     return (isLeapYear(year) ? 29 : 28);

    // return 30;
}

int nOfHoursInMonth(short year, short month)
{
    return nOfDaysInMonth(year, month) * 24;
}

int nOfMinutesInMonth(short year, short month)
{
    return nOfHoursInMonth(year, month) * 60;
}

int nOfSecondsInMonth(short year, short month)
{
    return nOfMinutesInMonth(year, month) * 60;
}

int main()
{
    short year = readShortVar("year");
    short month = readShortVar("month");
    cout << "Number of Days in Month [" << month << "] is " << nOfDaysInMonth(year, month) << endl;
    cout << "Number of Hours in Month [" << month << "] is " << nOfHoursInMonth(year, month) << endl;
    cout << "Number of Minutes in Month [" << month << "] is " << nOfMinutesInMonth(year, month) << endl;
    cout << "Number of Seconds in Month [" << month << "] is " << nOfSecondsInMonth(year, month) << endl;
    return 0;
}