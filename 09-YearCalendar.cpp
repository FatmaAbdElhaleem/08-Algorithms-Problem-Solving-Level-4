#include <iostream>
#include <iomanip>
using namespace std;

// Problem: #8/4
// Write a program to print Year Calendar.
// Please enter a year? 2022

//_______________________________
//       Calendar - 2022
//
//____________Jan_______________
// Sun	Mon	Tue	Wed	Thu	Fri	Sat
//                          1
// 2	3	4	5	6	7	8
// 9	10	11	12	13	14	15
// 16	17	18	19	20	21	22
// 23	24	25	26	27	28	29
// 30	31
//_______________________________
//
//____________Feb_______________
// Sun	Mon	Tue	Wed	Thu	Fri	Sat
//          1	2	3	4	5
// 6    7	8	9	10	11	12
// 13   14	15	16	17	18	19
// 20   21	22	23	24	25	26
// 27   28
//_______________________________

//____________Mar_______________
//...

// Note: January 2022 started on Saturday (Day Order 6), so day 1 appears under Saturday.
// February 2022 started on Tuesday (Day Order 2), so day 1 appears under Tuesday.

struct sDate
{
    short year;
    short month = 1;
    short day = 1;
};

short readYear()
{
    short year;
    cout << "Please enter a year? ";
    cin >> year;
    return year;
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
        if (++j % 7 == 0)
            cout << endl;
    };
    cout << "\n_______________________________________________\n\n";
}

void printYearCalendar(sDate &date)
{
    string monthName;
    short nOfDays, startDayOrder;

    cout << "_______________________________________________\n\n";
    cout << "                 Calendar - " << date.year << "\n\n";
    for (int i = 1; i <= 12; i++)
    {
        date.month = i;
        monthName = getMonthName(date.month);
        nOfDays = nOfDaysInMonth(date.year, date.month);
        startDayOrder = calcDayOrder(date);
        printMonthCalendar(monthName, nOfDays, startDayOrder);
    }
}

int main()
{
    sDate date;
    date.year = readYear();
    printYearCalendar(date);
}