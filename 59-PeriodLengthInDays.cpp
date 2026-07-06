#include <iostream>
using namespace std;

// Problem: #59
// Write a program to read a Period and calculate period length in days?

// Enter Period :
// Enter Start Date:

// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Enter End Date:

// Please enter a Day? 5
// Please enter a Month? 1
// Please enter a Year? 2022

// Period Length is: 4
// Period Length (Including End Date) is: 5

struct stDate
{
    short year;
    short month;
    short day;
};

struct stPeriod
{
    stDate dateFrom;
    stDate dateTo;
};

stDate readDate()
{
    stDate date;
    cout << "Please enter a day? ";
    cin >> date.day;
    cout << "Please enter a Month? ";
    cin >> date.month;
    cout << "Please enter a year? ";
    cin >> date.year;
    return date;
}

stPeriod readPeriod()
{
    stPeriod period;
    cout << "Enter Start Date:\n";
    period.dateFrom = readDate();
    cout << "\nEnter End Date:\n";
    period.dateTo = readDate();

    return period;
}

bool isDate1BeforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year ? true : (date1.year == date2.year ? ((date1.month == date2.month) ? (date1.day < date2.day) : (date1.month < date2.month)) : false));
}

bool areDatesEqual(stDate date1, stDate date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
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

bool isLastDayInMonth(stDate date)
{
    return (date.day == nOfDaysInMonth(date.year, date.month));
}

bool isLastMonthInYear(short month)
{
    return (month == 12);
}

stDate increaseDateByOneDay(stDate date)
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

int DiffInDays(stDate date1, stDate date2, bool includeEndDay = false)
{
    int diffDays = 0;
    while (isDate1BeforeDate2(date1, date2))
    {
        diffDays++;
        date1 = increaseDateByOneDay(date1);
    }
    return includeEndDay ? ++diffDays : diffDays;
}

int calcPeriodLength(stPeriod period, bool includeEndDay = false)
{
    return DiffInDays(period.dateFrom, period.dateTo, includeEndDay);
}

int main()
{
    stPeriod period;
    cout << "\nEnter Period :\n\n";
    period = readPeriod();
    cout << "\nPeriod Length is: " << calcPeriodLength(period) << endl;
    cout << "Period Length (Including End Date) is: " << calcPeriodLength(period, true) << endl;
}