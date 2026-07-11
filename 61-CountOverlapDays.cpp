#include <iostream>
using namespace std;

// Problem: #61
// Write a program to read two periods then count overlap days?

// Enter Period 1 :
// Enter Start Date:

// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Enter End Date:

// Please enter a Day? 10
// Please enter a Month? 1
// Please enter a Year? 2022

// Enter Period 2 :
// Enter Start Date:

// Please enter a Day? 5
// Please enter a Month? 1
// Please enter a Year? 2022

// Enter End Date:

// Please enter a Day? 15
// Please enter a Month? 1
// Please enter a Year? 2022

// Overlap Days Count Is: 6

struct stDate
{
    short year;
    short month;
    short day;
};

struct stPeriod
{
    stDate pStart;
    stDate pEnd;
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
    period.pStart = readDate();
    cout << "\nEnter End Date:\n";
    period.pEnd = readDate();

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

bool isDate1AfterDate2(stDate date1, stDate date2)
{
    return (!isDate1BeforeDate2(date1, date2) && !areDatesEqual(date1, date2));
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

bool periodsOverlapOrNot(stPeriod period1, stPeriod period2)
{
    if (isDate1BeforeDate2(period1.pEnd, period2.pStart) || isDate1BeforeDate2(period2.pEnd, period1.pStart))
        return false;
    return true;
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

// solution 1:
// int countOverlapDays(stPeriod period1, stPeriod period2)
// {
//     if (!periodsOverlapOrNot(period1, period2))
//         return 0;

//     stDate end;
//     stDate start;

//     end = isDate1BeforeDate2(period1.pEnd, period2.pEnd) ? period1.pEnd : period2.pEnd;
//     start = isDate1BeforeDate2(period1.pStart, period2.pStart) ? period2.pStart : period1.pStart;
//     return DiffInDays(end, start, true);
// }

// solution 2:

int calcPeriodLength(stPeriod period, bool includeEndDay = false)
{
    return DiffInDays(period.pStart, period.pEnd, includeEndDay);
}

bool dateWithinPeriodOrNot(stPeriod period, stDate dateToCheck)
{
    return (!isDate1BeforeDate2(dateToCheck, period.pStart) && !isDate1BeforeDate2(period.pEnd, dateToCheck));
}

int countOverlapDays(stPeriod period1, stPeriod period2)
{
    if (!periodsOverlapOrNot(period1, period2))
        return 0;

    int count = 0;
    int period1Length = calcPeriodLength(period1);
    int period2Length = calcPeriodLength(period2);

    if (period2Length < period1Length)
    {
        stPeriod temp;
        temp = period1;
        period1 = period2;
        period2 = temp;
    }

    while (!isDate1AfterDate2(period1.pStart, period1.pEnd))
    {
        if (dateWithinPeriodOrNot(period2, period1.pStart))
            count++;

        period1.pStart = increaseDateByOneDay(period1.pStart);
    }
    return count;
}

// solution 3:
// int countOverlapDays(stPeriod period1, stPeriod period2)
// {
//     if (periodsOverlapOrNot(period1, period2))
//     {
//         int count = 0;
//         if (isDate1BeforeDate2(period2.pStart, period1.pStart))
//         {
//             stPeriod temp;
//             temp = period1;
//             period1 = period2;
//             period2 = temp;
//         }
//         while (!isDate1AfterDate2(period1.pStart, period1.pEnd) && !isDate1AfterDate2(period2.pStart, period2.pEnd))
//         {
//             if (areDatesEqual(period2.pStart, period1.pStart))
//             {
//                 count++;
//                 period2.pStart = increaseDateByOneDay(period2.pStart);
//             }
//             period1.pStart = increaseDateByOneDay(period1.pStart);
//         }
//         return count;
//     }
//     else
//         return 0;
// }

int main()
{
    stPeriod period1, period2;
    cout << "\nEnter Period 1:\n\n";
    period1 = readPeriod();

    cout << "\nEnter Period 2:\n\n";
    period2 = readPeriod();

    cout << "\nOverlap Days Count Is: " << countOverlapDays(period1, period2) << endl;
}