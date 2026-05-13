#include <iostream>
#include <iomanip>
using namespace std;

// Problem: #8/4
// Write a program to print Month Calendar.

// Please enter a year? 2022
// Please enter a Month? 9

//____________Sep_______________
//
// Sun	Mon	Tue	Wed	Thu	Fri	Sat
//                  1	2	3
// 4    5	6	7	8	9	10
// 11   12	13	14	15	16	17
// 18   19	20	21	22	23	24
// 25   26	27	28	29	30
//_______________________________

// Note: September 2022 started on Thursday (Day Order 4),
// so the calendar should have empty cells for Sun-Wed (Days 0-3),
// then day 1 starting at Thu (Day 4).

struct sDate
{
    short year;
    short month;
    short day = 1;
};

void readYear(sDate &date)
{
    cout << "Please enter a year? ";
    cin >> date.year;
    cout << "Please enter a Month? ";
    cin >> date.month;
}

string getMonthName(short monthIndex)
{
    string monthArr[] = {"Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec"};
    return monthArr[monthIndex - 1];
}

short calcDayOrder(sDate date)
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

void printMonthCalendar(string monthName, short nOfDays, short startDayOrder)
{
    cout << "_____________________" << monthName << "_______________________\n\n";
    cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    int j;
    for (j = 0; j < startDayOrder; j++)
        cout << setw(5) << " ";

    for (int i = 1; i <= nOfDays; i++)
    {
        cout << left << setw(5) << i;
        //  if (++j == 7)
        //     cout << endl;
        //     j=0;
        if (++j % 7 == 0)
            cout << endl;
    };
    cout << "\n_______________________________________________\n";
}

int main()
{
    sDate date;
    readYear(date);
    string monthName = getMonthName(date.month);
    short nOfDays = nOfDaysInMonth(date.year, date.month);
    short startDayOrder = calcDayOrder(date);
    printMonthCalendar(monthName, nOfDays, startDayOrder);
}