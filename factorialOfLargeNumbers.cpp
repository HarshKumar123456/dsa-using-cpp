#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


void printArray(vector<int> arr) {
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}

void multiplyAndStoreInVector(int number, vector<int> &result)
{
    // cout << "_____________________________" << endl;
    int product = 0;
    int carry = 0;

    // printArray(result);
    // cout << "Multiplying " << number << endl;

    for (int i = 0; i < result.size(); i++)
    {
        product = result[i] * number + carry;
        result[i] = product % 10;
        carry = product / 10;
    }

    while (carry != 0)
    {
        // cout << "We are having carry " << carry << endl;
        result.push_back(carry % 10);
        carry /= 10;
    }
}

string calculateFactorial(int n)
{
    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        multiplyAndStoreInVector(i, result);
    }

    string factorialString = "";

    for (int i = result.size() - 1; i >= 0; i--)
    {
        factorialString += (result[i] + '0');
    }

    return factorialString;
}

int main()
{
    int number = 24;
    string factorial = calculateFactorial(number);

    cout << "Factorial is: " << factorial << endl;

    return 0;
}