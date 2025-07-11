#include <iostream>
using namespace std;

int pow(int number, int power){
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

int main()
{
    int number;
    cout << "Enter negative number in input: " << endl;
    cin >> number;

    int binaryNumber = 0;
    int negativeDecimalNumber = number;

    if (negativeDecimalNumber > 0)
    {
        negativeDecimalNumber *= -1;
    }

    // Now we have Negative Decimal Number With us

    // Convert this Number to Positive Decimal Number
    int positiveDecimalNumber = negativeDecimalNumber * -1;
    int power = 0;
    while (positiveDecimalNumber != 0)
    {
        int bit = positiveDecimalNumber & 1;
        binaryNumber = binaryNumber + bit*pow(10, power);
        positiveDecimalNumber = positiveDecimalNumber >> 1;
        power++;
    }
    cout << "Positive Binary converted number is : " << binaryNumber << endl;

    // Find how many digits we have in binary representation of Positive Decimal Number
    int totalDigitsInBinaryNumber = 0;
    while (binaryNumber)
    {
        totalDigitsInBinaryNumber++;
        binaryNumber /= 10; 
    }
    cout << "Total digits in binary number are: " << totalDigitsInBinaryNumber << endl;

    // Extract exactly that number of binary digits from the negative number
    binaryNumber = 0;
    power = 0;
    cout << "Negative Decimal Number: " << negativeDecimalNumber << endl;
    while (totalDigitsInBinaryNumber)
    {
        int bit = negativeDecimalNumber & 1;
        // cout << "For bit: " << bit << " " << " and power " << power << " ";
        binaryNumber = binaryNumber + bit*pow(10, power);
        negativeDecimalNumber = negativeDecimalNumber >> 1;
        power++;
        totalDigitsInBinaryNumber--;
        cout << "We get binary number: "<< binaryNumber << endl;
    }
    cout << "Negative Binary converted number is : " << binaryNumber << endl;
    // Print the result

    cout << "Except these: " << binaryNumber <<" bits all bits at the end will be 1 in binary representation of " << number << endl;

    return 0;
}