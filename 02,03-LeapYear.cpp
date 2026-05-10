#include <iostream>
using namespace std;

// Problem: #2/4
// Write a program to check if year is a leap year or not.

// Note:
// All years which are perfectly divisible by 4 are leap years
// except for century years (years ending with 00),
// which are leap years only if they are perfectly divisible by 400.

// Problem: #3/4
// simplify the function into a one-line.

short readYear()
{
    short year;
    cout << "Enter a year? ";
    cin >> year;
    return year;
}

bool isLeapYear(short year)
{
    // if (year % 4 != 0)
    // {
    //     return false;
    // }
    // if (year % 100 == 0 && year % 400 != 0)
    // {
    //     return false;
    // }
    // return true;
    return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}

int main()
{
    short year = readYear();
    if (isLeapYear(year))
        cout << year << " is a leap year\n";
    else
        cout << year << " not a leap year\n";
}