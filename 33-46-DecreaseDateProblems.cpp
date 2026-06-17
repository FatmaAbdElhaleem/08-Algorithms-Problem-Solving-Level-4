#include <iostream>
using namespace std;

// Problems: #33-#46
// Write a program to read a date and make functions to Decrease date as follows:

// DecreaseDateByOneDay
// DecreaseDateByXDays
// DecreaseDateByOneWeek
// DecreaseDateByXWeeks
// DecreaseDateByOneMonth
// DecreaseDateByXMonths
// DecreaseDateByOneYear
// DecreaseDateByXYears
// DecreaseDateByXYearsFaster
// DecreaseDateByOneDecade
// DecreaseDateByXDecades
// DecreaseDateByXDecadesFaster
// DecreaseDateByOneCentury
// DecreaseDateByOneMillennium

// Please enter a Day? 31
// Please enter a Month? 12
// Please enter a Year? 2022

// Date After:

// 01- Subtracting one day is: 30/12/2022
// 02- Subtracting 10 days is: 20/12/2022
// 03- Subtracting one week is: 13/12/2022
// 04- Subtracting 10 weeks is: 4/10/2022
// 05- Subtracting one month is: 4/9/2022
// 06- Subtracting 5 months is: 4/4/2022
// 07- Subtracting one year is: 4/4/2021
// 08- Subtracting 10 Years is: 4/4/2011
// 09- Subtracting 10 Years (faster) is: 4/4/2001
// 10- Subtracting one Decade is: 4/4/1991
// 11- Subtracting 10 Decades is: 4/4/1891
// 12- Subtracting 10 Decades (faster) is: 4/4/1791
// 13- Subtracting One Century is: 4/4/1691
// 14- Subtracting One Millennium is: 4/4/691

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

// decreaseDateByOneDay
sDate decreaseDateByOneDay(sDate date)
{
    if (date.day == 1)
    {
        if (date.month == 1)
        {
            date.year--;
            date.month = 12;
            date.day = 31;
        }
        else
        {
            date.month--;
            date.day = nOfDaysInMonth(date.year, date.month);
        }
    }
    else
        date.day--;
    return date;
}

// decreaseDateByXDays
sDate decreaseDateByXDays(sDate date, int xDays)
{
    for (int i = 0; i < xDays; i++)
    {
        date = decreaseDateByOneDay(date);
    }
    return date;
}

// decreaseDateByOneWeek

sDate decreaseDateByOneWeek(sDate date)
{
    return decreaseDateByXDays(date, 7);
}

// decreaseDateByXWeeks
sDate decreaseDateByXWeeks(sDate date, int xWeeks)
{
    for (int i = 0; i < xWeeks; i++)
    {
        date = decreaseDateByOneWeek(date);
    }
    return date;
}

// decreaseDateByOneMonth
sDate decreaseDateByOneMonth(sDate date)
{
    short lastMonth = date.month == 1 ? 12 : date.month - 1;
    short daysOfLastMonth;
    if (date.month == 1)
        date.year--;

    date.month = lastMonth;
    daysOfLastMonth = nOfDaysInMonth(date.year, lastMonth);
    date.day = date.day > daysOfLastMonth ? daysOfLastMonth : date.day;

    return date;
}

// decreaseDateByXMonths
sDate decreaseDateByXMonths(sDate date, int xMonths)
{
    for (int i = 0; i < xMonths; i++)
    {
        date = decreaseDateByOneMonth(date);
    }
    return date;
}

// decreaseDateByOneYear
sDate decreaseDateByOneYear(sDate date)
{
    date.year--;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

// decreaseDateByXYears
sDate decreaseDateByXYears(sDate date, int xYears)
{
    for (int i = 0; i < xYears; i++)
    {
        date = decreaseDateByOneYear(date);
    }
    return date;
}

// decreaseDateByXYearsFaster
sDate decreaseDateByXYearsFaster(sDate date, int xYears)
{
    date.year -= xYears;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

// decreaseDateByOneDecade
sDate decreaseDateByOneDecade(sDate date)
{
    return decreaseDateByXYearsFaster(date, 10);
}

// decreaseDateByXDecades
sDate decreaseDateByXDecades(sDate date, int xDecade)
{
    for (int i = 0; i < xDecade; i++)
        date = decreaseDateByOneDecade(date);
    return date;
}

// decreaseDateByXDecadesFaster
sDate decreaseDateByXDecadesFaster(sDate date, int xDecade)
{
    date.year -= xDecade * 10;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

// decreaseDateByOneCentury
sDate decreaseDateByOneCentury(sDate date)
{
    date.year -= 100;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

// decreaseDateByOneMillennium
sDate decreaseDateByOneMillennium(sDate date)
{
    date.year -= 1000;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

int main()
{
    sDate date, newDate;
    date = readDate();
    newDate = decreaseDateByOneDay(date);
    cout << "\nDate After:\n";
    cout << "\n01- Subtracting one day is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByXDays(newDate, 10);
    cout << "\n02- Subtracting 10 days is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByOneWeek(newDate);
    cout << "\n03- Subtracting one week is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByXWeeks(newDate, 10);
    cout << "\n04- Subtracting 10 weeks is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByOneMonth(newDate);
    cout << "\n05- Subtracting one month is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByXMonths(newDate, 5);
    cout << "\n06- Subtracting 5 months is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByOneYear(newDate);
    cout << "\n07- Subtracting one year is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByXYears(newDate, 10);
    cout << "\n08- Subtracting 10 years is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByXYearsFaster(newDate, 10);
    cout << "\n09- Subtracting 10 years faster is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByOneDecade(newDate);
    cout << "\n10- Subtracting one decade is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByXDecades(newDate, 10);
    cout << "\n11- Subtracting 10 decades is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByXDecadesFaster(newDate, 10);
    cout << "\n12- Subtracting 10 decades faster is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByOneCentury(newDate);
    cout << "\n13- Subtracting one century is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = decreaseDateByOneMillennium(newDate);
    cout << "\n14- Subtracting one millennium is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
}