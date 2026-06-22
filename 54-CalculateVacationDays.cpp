#include <iostream>
using namespace std;

// Problem:
// Write a program to read Vacation Period DateFrom and DateTo and make a function
// to calculate the actual vacation days.
// Note: Weekends are excluded.

// Vacation Starts:
// Please enter a Day? 1
// Please enter a Month? 9
// Please enter a Year? 2022

// Vacation Ends:
// Please enter a Day? 5
// Please enter a Month? 9
// Please enter a Year? 2022

// Vacation From: Thu, 1/9/2022
// Vacation To: Mon, 5/9/2022

// Actual Vacation Days is: 2

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

string getDayName(short dayOrder)
{
    string daysArr[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return daysArr[dayOrder];
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

bool isDate1BeforeDate2(sDate date1, sDate date2)
{
    return (date1.year < date2.year || date1.year == date2.year && ((date1.month == date2.month && date1.day < date2.day) || (date1.month < date2.month)));
}

int DiffInDays(sDate date1, sDate date2, bool includeEndDay = false)
{
    int diffDays = 0;
    while (isDate1BeforeDate2(date1, date2))
    {
        diffDays++;
        date1 = increaseDateByOneDay(date1);
    }
    return includeEndDay ? ++diffDays : diffDays;
}

short calcDayOrder(sDate &date)
{
    short a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + 12 * a - 2;
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

bool isWeekEnd(sDate date)
{
    short dayOrder = calcDayOrder(date);
    return (dayOrder == 5 || dayOrder == 6);
}

// solution 1:

short weekendDaysNumber(sDate dateFrom, sDate dateTo)
{
    short weekendCount = 0;
    while (isDate1BeforeDate2(dateFrom, dateTo))
    {
        if (isWeekEnd(dateFrom))
            weekendCount++;
        dateFrom = increaseDateByOneDay(dateFrom);
    }
    return weekendCount;
}

int calcActualVacation(sDate vacDateFrom, sDate vacDateTo)
{
    return DiffInDays(vacDateFrom, vacDateTo) - weekendDaysNumber(vacDateFrom, vacDateTo);
}

// solution 2:
bool isBusinessDay(sDate date)
{
    return !isWeekEnd(date);
}

short calcActualVacation2(sDate vacDateFrom, sDate vacDateTo)
{
    short daysCount = 0;
    while (isDate1BeforeDate2(vacDateFrom, vacDateTo))
    {
        if (isBusinessDay(vacDateFrom))
            daysCount++;
        vacDateFrom = increaseDateByOneDay(vacDateFrom);
    }
    return daysCount;
}

int main()
{
    sDate vacDateFrom, vacDateTo;
    cout << "\nVacation Starts:\n";
    vacDateFrom = readDate();
    cout << "\nVacation Ends:\n";
    vacDateTo = readDate();
    cout << "\n\nVacation From: " << getDayName(calcDayOrder(vacDateFrom)) << " " << vacDateFrom.day << "/" << vacDateFrom.month << "/" << vacDateFrom.year;
    cout << "\nVacation To: " << getDayName(calcDayOrder(vacDateTo)) << " " << vacDateTo.day << "/" << vacDateTo.month << "/" << vacDateTo.year << endl;
    cout << "Actual Vacation Days is: " << calcActualVacation2(vacDateFrom, vacDateTo);
}