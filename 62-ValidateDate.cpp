#include <iostream>
using namespace std;

// Problem: #62
// Write a program to read Date and write a function to validate this date

// Please enter a Day: 35
// Please enter a Month: 1
// Please enter a Year: 2022

// No, Date is NOT a valid date

// Please enter a Day: 29
// Please enter a Month: 2
// Please enter a Year: 2022

// No, Date is NOT a valid date (2022 is not a leap year)

// Please enter a Day: 29
// Please enter a Month: 2
// Please enter a Year: 2000

// Yes, Date is a valid date (2000 is a leap year)

// Please enter a Day: 25
// Please enter a Month: 15
// Please enter a Year: 2022

// No, Date is NOT a valid date (Month 15 doesn't exist)

struct stDate
{
    short year;
    short month;
    short day;
};

stDate readDate()
{
    stDate date;
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

bool isValidDate(stDate date)
{
    return (date.year > 0 && date.month > 0 && date.month <= 12 && date.day <= nOfDaysInMonth(date.year, date.month) && date.day > 0);

    // another way to write the code
    // if (date.year < 1)
    //     return false;
    // if (date.month < 1 || date.month > 12)
    //     return false;
    // return (date.day <= nOfDaysInMonth(date.year, date.month) && date.day > 0);
}

int main()
{
    stDate date;
    date = readDate();
    if (isValidDate(date))
        cout << "\nYes, Date is a valid date\n";
    else
        cout << "\nNo, Date is NOT a valid date\n";
}