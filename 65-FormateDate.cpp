#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Problem: #65
// Write a program to read Date and write a function to format that date.
// Please Enter Date dd/mm/yyyy? 31/12/2022

// 31/12/2022
// 2022/31/12
// 12/31/2022
// 12-31-2022
// 31-12-2022

// Day: 31, Month: 12, Year: 2022

struct stDate
{
    short year;
    short month;
    short day;
};

string readDateString(string message)
{
    string dateStr;
    cout << message;
    getline(cin >> ws, dateStr);
    return dateStr;
}

vector<string> splitString(string dateStr, string delimiter = "/")
{
    vector<string> vDateParts;
    short pos = 0;
    string word;
    while ((pos = dateStr.find(delimiter)) != std::string::npos)
    {
        word = dateStr.substr(0, pos);
        if (!word.empty())
        {
            vDateParts.push_back(word);
        }
        dateStr.erase(0, pos + delimiter.length());
    }
    if (!dateStr.empty())
    {
        vDateParts.push_back(dateStr);
    }
    return vDateParts;
}

stDate convertStrToDate(string dateStr)
{
    stDate date;
    vector<string> vDateParts = splitString(dateStr);
    date.day = stoi(vDateParts[0]);
    date.month = stoi(vDateParts[1]);
    date.year = stoi(vDateParts[2]);
    return date;
}

// solution 1:
// string formatDate(stDate date, string dateFormat = "dd/mm/yyyy")
// {
//     dateFormat.replace(dateFormat.find("dd"), 2, to_string(date.day));
//     dateFormat.replace(dateFormat.find("mm"), 2, to_string(date.month));
//     dateFormat.replace(dateFormat.find("yyyy"), 4, to_string(date.year));
//     return dateFormat;
// }

// solution 2:
string replaceWordInStr(string str, string wordToReplace, string replaceTo)
{
    short pos;
    while ((pos = str.find(wordToReplace)) != string::npos)
    {
        str.replace(pos, wordToReplace.length(), replaceTo);
    }
    return str;
}

string formatDate(stDate date, string dateFormat = "dd/mm/yyyy")
{
    dateFormat = replaceWordInStr(dateFormat, "dd", to_string(date.day));
    dateFormat = replaceWordInStr(dateFormat, "mm", to_string(date.month));
    dateFormat = replaceWordInStr(dateFormat, "yyyy", to_string(date.year));
    return dateFormat;
}

int main()
{
    string dateString = readDateString("Please enter Date (dd/mm/yyyy): ");
    stDate date = convertStrToDate(dateString);
    cout << formatDate(date, "yyyy/dd/mm") << endl;
    cout << formatDate(date, "mm/dd/yyyy") << endl;
    cout << formatDate(date, "mm-dd-yyyy") << endl;
    cout << formatDate(date, "dd-mm-yyyy") << endl;
    cout << formatDate(date, "dd-mm-yyyy") << endl;
    cout << formatDate(date, "Day: dd, Month: mm, Year: yyyy") << endl;
}