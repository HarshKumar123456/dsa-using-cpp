#include <iostream>
#include <stack>
using namespace std;


int findMinimumCostToMakeBracketsValid(string &bracketExpression) {
    int lengthOfExpression = bracketExpression.length();

    // Case 1: Odd Length: No Way to make them valid
    if (lengthOfExpression % 2 != 0)
    {
        // cout << "Bro It cannot be made valid, because iski length Odd hai aur valid ke liye even hona padega." << endl;
        return -1;
    }

    // Case 2: Even Length
    // Remove The valid pairs of Brackets from the expression by repeatedly pushing into the Stack
    stack<char> s;

    for (int i = 0; i < lengthOfExpression; i++)
    {
        char bracket = bracketExpression[i];
        // Check If on the Top there is closing bracket, Agar hai to pop karo aur aage badho is bracket ko discard kardo else push into stack
        if (s.empty() == false && bracket == '}' && s.top() == '{')
        {
            s.pop();
        }
        else
        {
            s.push(bracket);   
        }
    }


    // Now we will be left with the stack ke andar ka expression like 
    // {{{{.... 
    // }}}}....  
    // ....}}}}{{{{....

    // Ab count karo ki opening brackets kitne hain aur closing kitne hain
    int openingBracketCount = 0;
    int closingBracketCount = 0;
    while (s.empty() != true)
    {
        if (s.top() == '{')
        {
            openingBracketCount++;
        }
        else{
            closingBracketCount++;
        }
        
        s.pop();
    }


    int cost = ((openingBracketCount + 1) / 2) + ((closingBracketCount + 1) / 2);

    return cost;
}


int main() {
    string bracketExpression;
    cout << "Enter the Brackets: ";
    cin >> bracketExpression;

    cout << "Cost to make this valid: " << findMinimumCostToMakeBracketsValid(bracketExpression) << endl;
    return 0;
}