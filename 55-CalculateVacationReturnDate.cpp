#include <iostream>
using namespace std;

// Problem: #55
// Write a program to read Vacation Start DateFrom and VacationDays,
// then make a function to calculate the vacation return Date.

// Note: Weekends are excluded.

// Vacation Starts:
// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Please enter vacation days? 23

// Return Date: Wed, 2/2/2022

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

short readVacationDays()
{
    short vacationDays;
    cout << "\nPlease enter vacation days? ";
    cin >> vacationDays;
    return vacationDays;
}

string getDayName(short dayOrder)
{
    string daysArr[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return daysArr[dayOrder];
}

short calcDayOrder(sDate &date)
{
    short a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + 12 * a - 2;
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
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

bool isWeekEnd(sDate date)
{
    short dayOrder = calcDayOrder(date);
    return (dayOrder == 5 || dayOrder == 6);
}

// solution 1:
// sDate calcVacationReturnDate(sDate vacDateFrom, short vacationDays)
// {
//     for (int i = 0; i < vacationDays; i++)
//     {
//         while (isWeekEnd(vacDateFrom))
//             vacDateFrom = increaseDateByOneDay(vacDateFrom);

//         vacDateFrom = increaseDateByOneDay(vacDateFrom);

//         while (isWeekEnd(vacDateFrom))
//             vacDateFrom = increaseDateByOneDay(vacDateFrom);
//     }
//     return vacDateFrom;
// }

// solution 2:
sDate calcVacationReturnDate(sDate vacDateFrom, short vacationDays)
{
    short weekendDays = 0;

    // we do not need this while loop because in for loop we check before increasing
    // while (isWeekEnd(vacDateFrom))
    //     vacDateFrom = increaseDateByOneDay(vacDateFrom);

    for (int i = 0; i < vacationDays + weekendDays; i++)
    {
        if (isWeekEnd(vacDateFrom))
            weekendDays++;
        vacDateFrom = increaseDateByOneDay(vacDateFrom);
    }

    while (isWeekEnd(vacDateFrom))
        vacDateFrom = increaseDateByOneDay(vacDateFrom);

    return vacDateFrom;
}

int main()
{
    cout << "\nVacation Starts:\n";
    sDate vacDateFrom = readDate();
    short vacDays = readVacationDays();
    sDate vacDateTo = calcVacationReturnDate(vacDateFrom, vacDays);
    cout << "Return Date: " << getDayName(calcDayOrder(vacDateTo)) << " , " << vacDateTo.day << " / " << vacDateTo.month << " / " << vacDateTo.year << endl;
}