#include <iostream>
using namespace std;

int evalPower(int number, int power)
{

	// Base case
	if (power == 0)
	{
		return 1;
	}

	// Solve One Case, Leave rest on recursion
	int half = evalPower(number, power / 2);
	if (power % 2 == 0)
		return half * half;
	else
		return number * half * half;
}

int main()
{
	int number, power;

	cout << "Enter number and power of it to calculate Please: ";
	cin >> number >> power;

	cout << "Result is: " << evalPower(number, power) << endl;

	cout << "We have taken TC: O( log (n) ) and SC: O( log (n) )" << endl;

	return 0;
}
