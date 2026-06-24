#include <iostream>
using namespace std;

// Problem: #57
// Write a program to read Date1 & Date2, and write a function to compare dates, it should return:
// -1 Before
// 0 Equal
// 1 After

// Enter Date1:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2000

// Enter Date2:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Compare Result = -1

// Enter Date1:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2000

// Enter Date2:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2000

// Compare Result = 0

// Enter Date1:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Enter Date2:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2000

// Compare Result = 1

struct sDate
{
    short year;
    short month;
    short day;
};

enum eCompareResult
{
    before = -1,
    equal = 0,
    after = 1
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

bool areDatesEqual(sDate date1, sDate date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

bool isDate1AfterDate2(sDate date1, sDate date2)
{
    return (!isDate1BeforeDate2(date1, date2) && !areDatesEqual(date1, date2));
}

eCompareResult compareDates(sDate date1, sDate date2)
{
    // solution 1:
    // if (isDate1BeforeDate2(date1, date2))
    //     return eCompareResult::before;
    // else if (areDatesEqual(date1, date2))
    //     return eCompareResult::equal;
    // else
    //     return eCompareResult::after;

    // solution 2:
    if (isDate1BeforeDate2(date1, date2))
        return eCompareResult::before;
    if (areDatesEqual(date1, date2))
        return eCompareResult::equal;

    return eCompareResult::after;
}

int main()
{
    sDate date1, date2;
    cout << "Enter Date1:\n";
    date1 = readDate();
    cout << "\nEnter Date2:\n";
    date2 = readDate();
    cout << "\nCompare Result = " << compareDates(date1, date2) << endl;
}