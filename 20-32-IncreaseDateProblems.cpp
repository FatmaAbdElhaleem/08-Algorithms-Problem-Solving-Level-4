#include <iostream>
using namespace std;

// Problem: #20-32/4
// Write a program to read a date and make functions to increase date as follows:

// IncreaseDateByXDays
// IncreaseDateByOneWeek
// IncreaseDateByXWeeks
// IncreaseDateByOneMonth
// IncreaseDateByXMonths
// IncreaseDateByOneYear
// IncreaseDateByXYears
// IncreaseDateByXYearsFaster
// IncreaseDateByOneDecade
// IncreaseDateByXDecade
// IncreaseDateByXDecadesFaster
// IncreaseDateByOneCentury
// IncreaseDateByOneMillennium

// Please enter a Day? 31
// Please enter a Month? 12
// Please enter a Year? 2022

// Date After:

// 01- Adding one day is: 1/1/2023
// 02- Adding 10 days is: 11/1/2023
// 03- Adding one week is: 18/1/2023
// 04- Adding 10 weeks is: 29/3/2023
// 05- Adding one month is: 29/4/2023
// 06- Adding 5 months is: 29/9/2023
// 07- Adding one year is: 29/9/2024
// 08- Adding 10 Years is: 29/9/2034
// 09- Adding 10 Years (faster) is: 29/9/2044
// 10- Adding one Decade is: 29/9/2054            // --> 10 years
// 11- Adding 10 Decades is: 29/9/2154            // --> 10n years
// 12- Adding 10 Decade (faster) is: 29/9/2254    // --> 10n years
// 13- Adding One Century is: 29/9/2354           // --> 100 years
// 14- Adding One Millennium is: 29/9/3354        // --> 1000 years

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

// IncreaseDateByOneDay
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

// IncreaseDateByXDays
sDate increaseDateByXDays(sDate date, int xDays)
{
    for (int i = 0; i < xDays; i++)
    {
        date = increaseDateByOneDay(date);
    }
    return date;
}

// IncreaseDateByOneWeek

// solution 1:
// bool isLastWeekInMonth(sDate date)
// {
//     return (date.day > nOfDaysInMonth(date.year, date.month) - 7);
// }

// sDate increaseDateByOneWeek(sDate date)
// {
//     if (isLastWeekInMonth(date))
//     {
//         if (isLastMonthInYear(date.month))
//         {
//             // 30 - 28 =2 --> 7-2=5
//             date.day = 7 - (nOfDaysInMonth(date.year, date.month) - date.day);
//             date.year++;
//             date.month = 1;
//         }
//         else
//         {
//             date.day = 7 - (nOfDaysInMonth(date.year, date.month) - date.day);
//             date.month++;
//         }
//     }
//     else
//         date.day = date.day + 7;
//     return date;
// }

// solution 2:
sDate increaseDateByOneWeek(sDate date)
{
    return increaseDateByXDays(date, 7);
}

// IncreaseDateByXWeeks
sDate increaseDateByXWeeks(sDate date, int xWeeks)
{
    for (int i = 0; i < xWeeks; i++)
    {
        date = increaseDateByOneWeek(date);
    }
    return date;
}

// IncreaseDateByOneMonth
sDate increaseDateByOneMonth(sDate date)
{
    short nextMonth = date.month == 12 ? 1 : date.month + 1;
    short daysOfNextMonth = nOfDaysInMonth(date.year, nextMonth);

    if (isLastMonthInYear(date.month))
    {
        date.year++;
    }

    date.month = nextMonth;
    date.day = date.day > daysOfNextMonth ? daysOfNextMonth : date.day;

    return date;
}

// IncreaseDateByXMonths
sDate increaseDateByXMonths(sDate date, int xMonths)
{
    for (int i = 0; i < xMonths; i++)
    {
        date = increaseDateByOneMonth(date);
    }
    return date;
}

// IncreaseDateByOneYear
sDate increaseDateByOneYear(sDate date)
{
    date.year++;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

// IncreaseDateByXYears
sDate increaseDateByXYears(sDate date, int xYears)
{
    for (int i = 0; i < xYears; i++)
    {
        date = increaseDateByOneYear(date);
    }
    return date;
}

// IncreaseDateByXYearsFaster
sDate increaseDateByXYearsFaster(sDate date, int xYears)
{
    date.year += xYears;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

// IncreaseDateByOneDecade
sDate increaseDateByOneDecade(sDate date)
{
    return increaseDateByXYearsFaster(date, 10);
}

// IncreaseDateByXDecades
sDate increaseDateByXDecades(sDate date, int xDecade)
{
    for (int i = 0; i < xDecade; i++)
        date = increaseDateByOneDecade(date);
    return date;
}

// IncreaseDateByXDecadesFaster
sDate increaseDateByXDecadesFaster(sDate date, int xDecade)
{
    date.year += xDecade * 10;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

// IncreaseDateByOneCentury
sDate increaseDateByOneCentury(sDate date)
{
    date.year += 100;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

// IncreaseDateByOneMillennium
sDate increaseDateByOneMillennium(sDate date)
{
    date.year += 1000;
    if (!isLeapYear(date.year) && date.month == 2 && date.day == 29)
        date.day = 28;
    return date;
}

int main()
{
    sDate date, newDate;
    date = readDate();
    newDate = increaseDateByOneDay(date);
    cout << "\nDate After:\n";
    cout << "\n01- Adding one day is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByXDays(newDate, 10);
    cout << "\n02- Adding 10 days is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByOneWeek(newDate);
    cout << "\n03- Adding one week is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByXWeeks(newDate, 10);
    cout << "\n04- Adding 10 weeks is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    //////
    newDate = increaseDateByOneMonth(newDate);
    cout << "\n05- Adding one month is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByXMonths(newDate, 10);
    cout << "\n06- Adding 10 months is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByOneYear(newDate);
    cout << "\n07- Adding one year is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByXYears(newDate, 10);
    cout << "\n08- Adding 10 years is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByXYearsFaster(newDate, 10);
    cout << "\n09- Adding 10 years faster is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByOneDecade(newDate);
    cout << "\n10- Adding one decade is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByXDecades(newDate, 10);
    cout << "\n11- Adding 10 decades is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByXDecadesFaster(newDate, 10);
    cout << "\n12- Adding 10 decades faster is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByOneCentury(newDate);
    cout << "\n13- Adding one century is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    newDate = increaseDateByOneMillennium(newDate);
    cout << "\n14- Adding one millennium is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
}