#include <iostream>
#include <ctime>
using namespace std;

// Problem:
// Write a program to read a date and make functions as follows:

// Overload the DayOfWeekOrder to take date structure
// IsEndOfWeek
// IsWeekEnd
// IsBusinessDay
// DaysUntilTheEndOfWeek
// DaysUntilTheEndOfMonth
// DaysUntilTheEndOfYear

// Today is Fri, 23/9/2022

// Is it End of Week?
// No Not end of week.

// Is it Weekend?
// Yes it is a weekend.

// Is it Business Day?
// No it is NOT a business day.

// Days until end of week : 1 Day(s).
// Days until end of month : 7 Day(s).
// Days until end of year : 99 Day(s).

struct sDate
{
    short year;
    short month;
    short day;
};

short calcDayOrder(sDate &date)
{
    short a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + 12 * a - 2;
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string getDayName(short dayOrder)
{
    string daysArr[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return daysArr[dayOrder];
}

bool isEndOfWeek(sDate date)
{
    short dayOrder = calcDayOrder(date);
    return (dayOrder == 6);
}

bool isWeekEnd(sDate date)
{
    short dayOrder = calcDayOrder(date);
    return (dayOrder == 5 || dayOrder == 6);
}

bool isBusinessDay(sDate date)
{
    return !isWeekEnd(date);
}

short daysUntilTheEndOfWeek(sDate date)
{
    return (6 - calcDayOrder(date));
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

int nOfDaysInYear(short year)
{
    return (isLeapYear(year) ? 366 : 365);
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

short daysUntilTheEndOfMonth(sDate date)
{
    return (nOfDaysInMonth(date.year, date.month) - date.day);
}

short daysUntilTheEndOfYear(sDate date)
{
    return (nOfDaysInYear(date.year) - numberOfDaysFromBeginningOfYear(date));
}

sDate getSystemDate()
{
    sDate todayDate;
    time_t t = time(0);
    tm *now = localtime(&t);

    todayDate.year = now->tm_year + 1900;
    todayDate.month = now->tm_mon + 1;
    todayDate.day = now->tm_mday;

    return todayDate;
}

int main()
{
    sDate date;
    date = getSystemDate();

    cout << "\nToday is " << getDayName(calcDayOrder(date)) << ", " << date.day << "/" << date.month << "/" << date.year << endl;
    cout << "\nIs it End of Week?\n";
    isEndOfWeek(date) ? cout << "Yes, it is end of week.\n" : cout << "No, it is Not end of week.\n";
    cout << "Is it Weekend?\n";
    isWeekEnd(date) ? cout << "Yes, it is a weekend.\n" : cout << "No, it is not a weekend.\n";
    cout << "Is it Business Day?\n";
    isBusinessDay(date) ? cout << "Yes, it is a business day.\n\n" : cout << "No, it is NOT a business day.\n\n";
    cout << "Days until end of week : " << daysUntilTheEndOfWeek(date) << " Day(s).\n";
    cout << "Days until end of month : " << daysUntilTheEndOfMonth(date) << " Day(s).\n";
    cout << "Days until end of year : " << daysUntilTheEndOfYear(date) << " Day(s).\n";
}