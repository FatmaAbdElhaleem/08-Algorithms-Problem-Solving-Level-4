#include <iostream>
#include <vector>
using namespace std;

// Problem: #63, #64
// Write a program to:
// Read Date String.
// Convert it to date structure
// Print Day, Month, Year separately.
// Then convert Date Structure to string and print it on the screen.

// Note: write the following functions:
// StringToDate.
// DateToString.

// Example:
// Please enter Date (dd/mm/yyyy): 25/12/2022
// Day: 25
// Month: 12
// Year: 2022

// Date after converting to string: 25/12/2022

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
    cin >> dateStr;
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

// solution2 for splitString function
// vector<string> splitString(string dateStr, char delimiter = '/')
// {
//     vector<string> vDateParts;
//     short pos = 0;
//     for (int i = 0; i < dateStr.length(); i++)
//     {
//         if (dateStr[i] == delimiter)
//         {
//             vDateParts.push_back(dateStr.substr(pos, i - pos));
//             pos = i + 1;
//         }
//     }
//     vDateParts.push_back(dateStr.substr(pos));
//     return vDateParts;
// }

stDate convertStrToDate(string dateStr)
{
    stDate date;
    vector<string> vDateParts = splitString(dateStr);
    date.day = stoi(vDateParts[0]);
    date.month = stoi(vDateParts[1]);
    date.year = stoi(vDateParts[2]);
    return date;
}

string convertDateToStr(stDate date)
{
    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

int main()
{
    string dateString = readDateString("Please enter Date (dd/mm/yyyy): ");
    stDate date = convertStrToDate(dateString);
    cout << "Day: " << date.day << '\n';
    cout << "Month: " << date.month << '\n';
    cout << "Year: " << date.year << '\n';
    cout << "\nDate after converting to string: " << convertDateToStr(date) << '\n';
}