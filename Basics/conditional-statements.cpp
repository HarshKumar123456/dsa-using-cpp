#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;
    // Normal if
    if (num > 0)
    {
        cout << "Bhai number is +ve" << endl;
    }

    // Normal if-else
    if (num > 0)
    {
        cout << "Bhai number is +ve" << endl;
    }
    else
    {
        cout << "Bhai number is not +ve" << endl;
    }

    // Nested if-else
    if (num > 0)
    {
        cout << "Bhai number is +ve" << endl;
    }
    else
    {
        // Normal if-else
        if (num < 0)
        {
            cout << "Bhai number is -ve" << endl;
        }
        else
        {
            cout << "Bhai number is 0" << endl;
        }
    }

    // Ladder if-else
    if (num < 0)
    {
        cout << "Bhai number is -ve" << endl;
    }
    else if (num > 0)
    {
        cout << "Bhai number is +ve" << endl;
    }
    else
    {
        cout << "Bhai number is 0" << endl;
    }


    // Check if Lowercase, Uppercase or Numeric
    char ch;
    cout << "Enter a character (a-z or A-Z or 0-9): " << endl;
    cin >> ch;

    if (ch >= 97 && ch <= 122) {
        cout << "Lowercase" << endl;
    }
    else if (ch >= 65 && ch <= 90)
    {   
        cout << "Uppercase" << endl;
    }
    else if (ch >= '0' && ch <= '9')
    {   
        cout << "Numeric" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    // Below lines will Print ASCII Codes for these characters
    cout << int ('a') << endl;
    cout << int ('z') << endl;
    cout << int ('A') << endl;
    cout << int ('Z') << endl;
    cout << int ('0') << endl;
    cout << int ('9') << endl;
    
    
    return 0;
}