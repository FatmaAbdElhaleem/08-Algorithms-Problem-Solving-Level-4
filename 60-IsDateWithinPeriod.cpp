#include <iostream>
using namespace std;

// Problem: #60
// Write a program to read a Period and Date, then check if date is within this period or not?

// Enter Period :
// Enter Start Date:

// Please enter a Day? 1
// Please enter a Month? 1
// Please enter a Year? 2022

// Enter End Date:

// Please enter a Day? 10
// Please enter a Month? 1
// Please enter a Year? 2022

// Enter Date to check:

// Please enter a Day? 5
// Please enter a Month? 1
// Please enter a Year? 2022

// Yes, Date is within period

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
bool dateWithinPeriodOrNot(stPeriod period, stDate dateToCheck)
{
    return (!isDate1BeforeDate2(dateToCheck, period.dateFrom) && !isDate1BeforeDate2(period.dateTo, dateToCheck));
    // return !(isDate1BeforeDate2(dateToCheck, period.dateFrom) || isDate1BeforeDate2(period.dateTo, dateToCheck));
}

// solution 2:
// bool dateWithinPeriodOrNot(stPeriod period, stDate dateToCheck)
// {
//     while (isDate1BeforeDate2(period.dateFrom, period.dateTo) || areDatesEqual(period.dateFrom, period.dateTo))
//     {
//         if (areDatesEqual(period.dateFrom, dateToCheck))
//             return true;
//         period.dateFrom = increaseDateByOneDay(period.dateFrom);
//     }
//     return false;
// }

int main()
{
    cout << "\nEnter Period :\n\n";
    stPeriod period = readPeriod();

    cout << "\nEnter Date to check: \n";
    stDate dateToCheck = readDate();

    if (dateWithinPeriodOrNot(period, dateToCheck))
        cout << "\nYes, Date is within period\n";
    else
        cout << "No, Date is not within period\n";
}