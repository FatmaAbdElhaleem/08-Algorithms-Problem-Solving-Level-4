#include <iostream>
using namespace std;

// Problem: #1/4
// Write a program to read a number and print the text of that number.

// Enter a Number? 5843
// Output: Five Thousands Eight Hundreds Forty Three

// Enter a Number? 2147483647
// Output: Two Billions One Hundred Forty Seven Millions Four Hundreds Eighty Three Thousands Six Hundreds Forty Seven

int readIntPositiveNumber()
{
    int number;
    do
    {
        cout << "Enter a Positive Intger Number? ";
        cin >> number;
    } while (number <= 0);
    return number;
}

string numberToText(int number)
{
    if (number == 0)
        return "";
    if (number > 0 && number < 20)
    {
        string arr1[] = {
            "One",
            "Two",
            "Three",
            "Four",
            "Five",
            "Six",
            "Seven",
            "Eight",
            "Nine",
            "Ten",
            "Eleven",
            "Twelve",
            "Thirteen",
            "Fourteen",
            "Fifteen",
            "Sixteen",
            "Seventeen",
            "Eighteen",
            "Nineteen"};
        return (arr1[number - 1] + " ");
    }
    if (number >= 20 && number < 100)
    {
        string arr2[] = {
            "Twenty",
            "Thirty",
            "Forty",
            "Fifty",
            "Sixty",
            "Seventy",
            "Eighty",
            "Ninety"};
        return arr2[number / 10 - 2] + " " + numberToText(number % 10);
    }
    if (number >= 100 && number < 1000)
    {
        return numberToText(number / 100) + "Hundred " + numberToText(number % 100);
    }
    if (number >= 1000 && number < 1000000)
    {
        return numberToText(number / 1000) + "Thousand " + numberToText(number % 1000);
    }
    if (number >= 1000000 && number < 1000000000)
    {
        return numberToText(number / 1000000) + "Million " + numberToText(number % 1000000);
    }
    if (number >= 1000000000)
    {
        return numberToText(number / 1000000000) + "Billion " + numberToText(number % 1000000000);
    }
    return "";
}

int main()
{
    int number = readIntPositiveNumber();
    cout << numberToText(number);
}