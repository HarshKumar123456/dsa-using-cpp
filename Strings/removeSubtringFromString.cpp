#include <iostream>
using namespace std;

bool checkIfWindowHasSubtring(string str, string subStr, int startWindow, int endWindow)
{
    for (int index = startWindow; index <= endWindow; index++)
    {
        if (str[index] !=  subStr[index - startWindow])
        {
            return false;
        }
        
    }
    
    return true;
}

int main()
{
    string str = "ababccabcnabababc";
    string subStr = "abc";

    int startWindow = 0;
    int endWindow = startWindow + subStr.size() - 1;

    while ( endWindow < str.size() ) {
        cout << "For window " << startWindow << " - " << endWindow << endl;
        cout << str << endl;


        if(checkIfWindowHasSubtring (str,subStr, startWindow, endWindow)){
            str.erase(str.begin() + startWindow, str.begin() + endWindow + 1);
            startWindow = startWindow - subStr.size();

            if(startWindow < 0){
                startWindow = -1;
            }
        }

        startWindow++;
        
        endWindow = startWindow + subStr.size() - 1;

        cout << str << endl;
        cout <<  endl;
    }

    cout << str << endl;

    return 0;
}