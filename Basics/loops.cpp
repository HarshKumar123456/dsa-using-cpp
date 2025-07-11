#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Print sum of all even integers '1 to num'
    int sum = 0;
    int temp = 1;
    while (temp <= num)
    {
        if (!(temp & 1)) // or ( temp % 2 == 0 )
        {
            sum += temp;
        }
        temp++;
    }
    cout << "Sum of all even integers '1 to num' : " << sum << endl;

    // Pattern Printing
    // 1 2 3 4 5 5 4 3 2 1
    // 1 2 3 4 * * 4 3 2 1
    // 1 2 3 * * * * 3 2 1
    // 1 2 * * * * * * 2 1
    // 1 * * * * * * * * 1

    int count = 1;
    while (count <= num)
    {
        // Phase 1: Printing Starting Numbers
        int startNumbers = 1;
        while (startNumbers <= (num - count + 1))
        {
            cout << startNumbers << " ";
            startNumbers = startNumbers + 1;
        }

        // Phase 2: Printing Starting Stars
        int startStars = 1;
        while (startStars <= count - 1)
        {
            cout << "*" << " ";
            startStars = startStars + 1;
        }

        // Phase 3: Printing Ending Stars
        int endingStars = 1;
        while (endingStars <= count - 1)
        {
            cout << "*" << " ";
            endingStars = endingStars + 1;
        }

        // Phase 4: Printing Ending Numbers
        int endingNumbers = 1;
        while (endingNumbers <= (num - count + 1))
        {
            cout << num - endingNumbers - count + 2 << " ";
            endingNumbers = endingNumbers + 1;
        }

        cout << endl;
        count = count + 1;
    }

    return 0;
}
