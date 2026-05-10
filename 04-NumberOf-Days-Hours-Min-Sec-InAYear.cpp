#include <iostream>
using namespace std;

// Problem: #4/4
// Write a program to print Number of:
// Days Hours Minutes Seconds in a certain Year.

// Please enter a year to check? 2000
// Number of Days in Year [2000] is 366
// Number of Hours in Year [2000] is 8784
// Number of Minutes in Year [2000] is 527040
// Number of Seconds in Year [2000] is 31622400

// Please enter a year to check? 1971
// Number of Days in Year [1971] is 365
// Number of Hours in Year [1971] is 8760
// Number of Minutes in Year [1971] is 525600
// Number of Seconds in Year [1971] is 31536000

// Note: Year 2000 is a leap year (divisible by 400), so it has 366 days.
// Year 1971 is not a leap year, so it has 365 days.

short readYear()
{
    short year;
    cout << "Please enter a year to check? ";
    cin >> year;
    return year;
}

bool isLeapYear(short year)
{
    return (year % 400 || year % 100 != 0 && year % 4 == 0);
}

int nOfDaysInYear(short year)
{
    return (isLeapYear(year) ? 366 : 365);
}

int nOfHoursInYear(short year)
{
    return nOfDaysInYear(year) * 24;
}

int nOfMinutesInYear(short year)
{
    return nOfHoursInYear(year) * 60;
}

int nOfSecondsInYear(short year)
{
    return nOfMinutesInYear(year) * 60;
}

int main()
{
    short year = readYear();
    cout << "Number of Days in Year [" << year << "] is " << nOfDaysInYear(year) << endl;
    cout << "Number of Hours in Year [" << year << "] is " << nOfHoursInYear(year) << endl;
    cout << "Number of Minutes in Year [" << year << "] is " << nOfMinutesInYear(year) << endl;
    cout << "Number of Seconds in Year [" << year << "] is " << nOfSecondsInYear(year) << endl;
    return 0;
}