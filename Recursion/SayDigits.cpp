#include <iostream>
#include <vector>
using namespace std;

void seperation()
{
    cout << endl;
    cout << endl;
}

void lineBreak()
{
    cout << endl;
}

void sayDigits(int number, vector<string> digits)
{
    if (number == 0)
    {
        return;
    }

    int lastDigittoBeSaid = number % 10;

    // Say Digits Preceding this last digit
    sayDigits(number / 10, digits);

    cout << digits[lastDigittoBeSaid] << " ";
}

int main()
{

    int number = 12340;
    vector<string> digits = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };

    sayDigits(number, digits);
    cout << endl;
	cout << "We have taken TC: O(n) and SC: O(n)" << endl;

    return 0;
}