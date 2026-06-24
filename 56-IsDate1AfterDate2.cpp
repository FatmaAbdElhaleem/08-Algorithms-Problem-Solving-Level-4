#include <iostream>
using namespace std;

// Problem: #56
// Write a program to read Date1 & Date2, and check if Date1 is after Date2 or not.

// Enter Date1:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Enter Date2:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// No, Date1 is NOT After Date2. (They are equal)

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

// solution 1:
// bool isDate1AfterDate2(sDate date1, sDate date2)
// {
//     return ((date1.year > date2.year) || (date1.year == date2.year && date1.month > date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day));
// }

// solution 2:
bool isDate1BeforeDate2(sDate date1, sDate date2)
{
    return (date1.year < date2.year ? true : (date1.year == date2.year ? ((date1.month == date2.month) ? (date1.day < date2.day) : (date1.month < date2.month)) : false));
}

bool areDatesEqual(sDate date1, sDate date2)
{
    // return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
    return date1.year == date2.year ? ((date1.month == date2.month) ? (date1.day == date2.day) : false) : false;
}

bool isDate1AfterDate2(sDate date1, sDate date2)
{
    return (!isDate1BeforeDate2(date1, date2) && !areDatesEqual(date1, date2));
}

int main()
{
    sDate date1, date2;
    cout << "Enter Date1:\n";
    date1 = readDate();
    cout << "\nEnter Date2:\n";
    date2 = readDate();
    if (isDate1AfterDate2(date1, date2))
        cout << "Yes, Date1 is After Date2.";
    else
        cout << "No, Date1 is NOT After Date2.";
}