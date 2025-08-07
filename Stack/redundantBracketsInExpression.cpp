#include <iostream>
#include <stack>
using namespace std;

bool isRedundantBracketsInExpression(string expression)
{
	// Check for Every set of Bracket Is there are operators to consume or not and if not then say this is Redundant Bracket
	stack<char> s;
	bool isRedundant = false;
	for (auto literal : expression)
	{
		if (literal == '(' || literal == '{' || literal == '[' || literal == '+' || literal == '-' || literal == '/' || literal == '*')
		{
			// Push Onto The Stack if Opening Bracket or Any Operator Has Encountered
			s.push(literal);
		}
		else if (literal == ')' || literal == '}' || literal == ']')
		{
			// If Closing Bracket Occurs then Repeatedly Pop Until Operators Until Opening Bracket appears or Stack is Empty and if Corresponding Opening Bracket does not appears then say this is Resundant Bracket
			char topElement = ' ';
			isRedundant = true;
			while (s.empty() == false)
			{
				topElement = s.top();
				if (topElement == '(' || topElement == '{' || topElement == '[')
				{
					break;
				}
				else
				{
					isRedundant = false;
					s.pop();
				}
			}

			if (isRedundant == false && literal == ')' && topElement == '(' || literal == '}' && topElement == '{' || literal == ']' && topElement == '[')
			{
				s.pop();
			}
			else
			{
				return true;
			}
		}
		else
		{
			// Operators case then no need to track Assuming the Expression is mathematically valid just brackets are there redundants
			continue;
		}
	}

	return isRedundant;
}

int main()
{
	string expression;
	cout << "Please Enter the Expression: ";
	cin >> expression;

	cout << "Your Entered Expression is: " << expression << endl;
	if (isRedundantBracketsInExpression(expression))
	{
		cout << "Bro it has Redundant Brackets. " << endl;
	}
	else
	{
		cout << "Bro it has no Redundant Brackets. " << endl;
	}
	return 0;
}
