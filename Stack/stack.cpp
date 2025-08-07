#include <iostream>
#include <stack>
using namespace std;

void reverseStringUsingStack(string &str)
{
    stack<char> charStack;

    char extractedChar = ' ';

    for (int i = 0; i < str.length(); i++)
    {
        extractedChar = str[i];
        charStack.push(extractedChar);
    }

    str = "";

    while (charStack.empty() == false)
    {
        extractedChar = charStack.top();
        // cout << "Fitted: " << extractedChar << endl;
        charStack.pop();

        str.push_back(extractedChar);
    }
}

void deleteFromMiddleOfStack(stack<int> &s, int size, int count)
{
    // Base Case
    if (s.empty() == true)
    {
        return ;
    }
    
    if (count == size / 2)
    {
        s.pop(); // Delete Middle Element
        return;
    }

    // Take One Number Side and Let the Recursion find the middle and delete
    int extractedNumber = s.top();
    s.pop();

    // Recursive Call
    deleteFromMiddleOfStack(s, size, count + 1);

    // Re Insert The Side Number Taken Earlier
    s.push(extractedNumber);
}

void print(stack<int> s)
{
    if (s.empty() == true)
    {
        return;
    }

    cout << "Printing Stack: " << endl;
    while (s.empty() == false)
    {
        cout << s.top() << endl;
        s.pop();
    }
}

bool validParenthesis(string parenthesis)
{
    if (parenthesis.length() == 0)
    {
        return true;
    }

    if (parenthesis.length() % 2 == 1)
    {
        return false;
    }

    stack<char> charStack;
    char extractedChar = ' ';

    for (int i = 0; i < parenthesis.length(); i++)
    {
        // Extract Bracket
        extractedChar = parenthesis[i];

        if (extractedChar == '(' || extractedChar == '{' || extractedChar == '[')
        {
            // If the Extracted Bracket is Opening Bracket then Store it to Stack
            charStack.push(extractedChar);
        }
        else
        {
            // If the Extracted Bracket is Closing Bracket then Find Corresponding Opening Bracket and if not found then return false
            if ((charStack.top() == '(' && extractedChar == ')') || (charStack.top() == '{' && extractedChar == '}') || (charStack.top() == '[' && extractedChar == ']'))
            {
                charStack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return charStack.empty();
}

void insertAtBottom(stack<int> &s, int element)
{
    // Base Case
    if (s.empty() == true)
    {
        s.push(element);
        return;
    }

    int extractNumber = s.top();
    s.pop();

    insertAtBottom(s, element);

    s.push(extractNumber);
}

void reverseStackUsingRecursion(stack<int> &s)
{
    // Base Case
    if (s.empty() == true)
    {
        return;
    }

    int extractNumber = s.top();
    s.pop();

    reverseStackUsingRecursion(s);

    insertAtBottom(s, extractNumber);
}

void sortedInsert(stack<int> &s, int element)
{
    // Base Case
    if (s.empty() == true || s.top() <= element)
    {
        s.push(element);
        return ;
    }
    
    int extractNumber = s.top();
    s.pop();

    sortedInsert(s,element);

    s.push(extractNumber);
}

void sortStack(stack<int> &s)
{
    // Base Case
    if (s.empty() == true)
    {
        return;
    }

    int extractNumber = s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s, extractNumber);
}

int main()
{
    string name = "Prime";

    cout << endl
         << "Before Reversing Using Stack:  " << name << endl;

    reverseStringUsingStack(name);

    cout << "After Reversing Using Stack:  " << name << endl
         << endl;

    stack<int> numbers;
    numbers.push(10);
    numbers.push(20);
    numbers.push(3);
    numbers.push(30);
    numbers.push(40);

    print(numbers);

    cout << "Deleting from the Middle of Stack: " << endl;
    deleteFromMiddleOfStack(numbers, 5, 0);

    print(numbers);

    cout << endl
         << "Inserting at Bottom: " << endl;

    insertAtBottom(numbers, 4);
    print(numbers);


    cout << endl
         << "Reversing the Stack: " << endl;

    reverseStackUsingRecursion(numbers);
    print(numbers);


    cout << endl
         << "Sorting the Stack: " << endl;

    sortStack(numbers);
    print(numbers);

    string parenthesis = "";
    cout << endl
         << "Yo! Bro!! Ab yo find karo ki yo ->'" << parenthesis << "'<- valid Parenthesis hai ya na? " << endl;

    if (validParenthesis(parenthesis))
    {
        cout << "Bhai Valid Parenthesis hai. " << endl;
    }
    else
    {
        cout << "Bhai Valid Parenthesis na hai. " << endl;
    }

    return 0;
}