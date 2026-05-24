#include <iostream>
using namespace std;

// Problem: #19/4
// Write a program to read a Date1, Date2 and make a function to calculate the difference in days.

// Note: if date2 is less than date1 print the results in Minutes

// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2000

// Difference is: -8036 Day(s).
// Difference (Including End Day) is: -8037 Day(s).

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

void swapDates(sDate &date1, sDate &date2)
{
    sDate tempDate = date1;
    date1 = date2;
    date2 = tempDate;
}

bool isDate1EqualDate2(sDate date1, sDate date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

int DiffInDays(sDate date1, sDate date2, bool includeEndDay = false)
{
    int diffDays = 0;
    short swapFlag = 1;

    if (!isDate1BeforeDate2(date1, date2) && !isDate1EqualDate2(date1, date2))
    {
        swapDates(date1, date2);
        swapFlag = -1;
    }

    while (isDate1BeforeDate2(date1, date2))
    {
        diffDays++;
        date1 = increaseDateByOneDay(date1);
    }

    // if you declared bool swapFlag =false; and if sawed =true;
    // includeEndDay ? ++diffDays : diffDays;
    // return swapFlag ? -diffDays : diffDays;

    return includeEndDay ? ++diffDays * swapFlag : diffDays * swapFlag;
}

int main()
{
    sDate date1, date2;
    date1 = readDate();
    cout << endl;
    date2 = readDate();

    cout << "Difference is: " << DiffInDays(date1, date2) << " Day(s).\n";
    cout << "Difference (Including End Day) is: " << DiffInDays(date1, date2, true) << " Day(s).\n";
}