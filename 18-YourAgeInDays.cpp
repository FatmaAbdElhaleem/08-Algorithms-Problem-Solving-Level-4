#include <iostream>
#include <ctime>
using namespace std;

// Problem: #18/4
// Write a program calculate your age in days.

// Please Enter Your Date of Birth:
// Please enter a Day? 6
// Please enter a Month? 11
// Please enter a Year? 1977

// Your Age is : 16391 Day(s).

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

int DiffInDays(sDate date1, sDate date2, bool includeEndDay = false)
{
    int diffDays = 0;
    while (isDate1BeforeDate2(date1, date2))
    {
        diffDays++;
        date1 = increaseDateByOneDay(date1);
    }
    return includeEndDay ? diffDays + 1 : diffDays;
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
    sDate dateOfBirth, todayDate;
    cout << "Please Enter Your Date of Birth:\n";
    dateOfBirth = readDate();
    cout << endl;
    todayDate = getSystemDate();
    cout << "Your Age is : " << DiffInDays(dateOfBirth, todayDate, true) << " Day(s).";
}