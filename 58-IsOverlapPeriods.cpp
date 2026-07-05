#include <iostream>
using namespace std;

// Problem: #58
// Write a program to read Two Periods and check if they overlap or not?

// Enter Period 1:

// Enter Start Date:
// Please enter a Day? 1
// Please enter a Month? 2
// Please enter a Year? 2022

// Enter End Date:
// Please enter a Day? 10
// Please enter a Month? 2
// Please enter a Year? 2022

// Enter Period 2:

// Enter Start Date:
// Please enter a Day? 5
// Please enter a Month? 2
// Please enter a Year? 2022

// Enter End Date:
// Please enter a Day? 15
// Please enter a Month? 2
// Please enter a Year? 2022

// Yes, Periods Overlap

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

// solution 1:
bool periodsOverlapOrNot(stPeriod period1, stPeriod period2)
{
    if (isDate1BeforeDate2(period1.dateTo, period2.dateFrom) || isDate1BeforeDate2(period2.dateTo, period1.dateFrom))
        return false;
    return true;
}

// solution 2:
// bool periodsOverlapOrNot(stPeriod period1, stPeriod period2)
// {
//     stDate startDate = period1.dateFrom;
//     while (isDate1BeforeDate2(period2.dateFrom, period2.dateTo) || areDatesEqual(period2.dateFrom, period2.dateTo))
//     {
//         period1.dateFrom = startDate;
//         while (isDate1BeforeDate2(period1.dateFrom, period1.dateTo))
//         {
//             if (areDatesEqual(period1.dateFrom, period2.dateFrom))
//                 return true;
//             period1.dateFrom = increaseDateByOneDay(period1.dateFrom);
//         }
//         period2.dateFrom = increaseDateByOneDay(period2.dateFrom);
//     }
//     return false;
// }

int main()
{
    stPeriod period1, period2;
    cout << "\nEnter Period 1:\n\n";
    period1 = readPeriod();

    cout << "\nEnter Period 2:\n\n";
    period2 = readPeriod();

    if (periodsOverlapOrNot(period1, period2))
        cout << "\nYes, Periods Overlap.\n";
    else
        cout << "\nNo, Periods do not Overlap.\n";
}