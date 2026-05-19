#include <iostream>
using namespace std;

// Problem: #13/4
// Write a program to read date1, date2 and check if Date1 is Less than Date2

// Please enter a Day? 12
// Please enter a Month? 2
// Please enter a Year? 2022

// Please enter a Day? 12
// Please enter a Month? 3
// Please enter a Year? 2022

// Yes, Date1 is Less than Date2.

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
    // solution 1:
    // if (date1.year == date2.year)
    // {
    //     if (date1.month == date2.month && date1.day < date2.day || date1.month < date2.month)

    //         return true;
    // }
    // else if (date1.year < date2.year)
    //     return true;

    // return false;

    // solution 2:
    // return (date1.year < date2.year || date1.year == date2.year && ((date1.month == date2.month &&date1.day < date2.day) || (date1.month < date2.month)));

    // solution 3:
    return (date1.year < date2.year ? true : (date1.year == date2.year ? ((date1.month == date2.month) ? (date1.day < date2.day) : (date1.month < date2.month)) : false));
}

int main()
{
    sDate date1, date2;
    date1 = readDate();
    cout << "\n";
    date2 = readDate();
    if (isDate1BeforeDate2(date1, date2))
        cout << "Yes, Date1 is Less than Date2.";
    else
        cout << "No, Date1 is not Less than Date2.";
}