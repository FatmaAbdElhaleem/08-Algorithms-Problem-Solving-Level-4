#include <iostream>
using namespace std;

// Problem: #14/4
// Write a program to read date1, date2 and check if Date1 Equals to Date2

// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2000

// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2000

// Yes, Date1 is Equal To Date2.

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

bool areDatesEqual(sDate date1, sDate date2)
{
    // return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
    return date1.year == date2.year ? ((date1.month == date2.month) ? (date1.day == date2.day) : false) : false;
}

int main()
{
    sDate date1, date2;
    date1 = readDate();
    cout << "\n";
    date2 = readDate();
    if (areDatesEqual(date1, date2))
        cout << "Yes, Date1 is equal to Date2.";
    else
        cout << "No, Date1 is not equal to Date2.";
}