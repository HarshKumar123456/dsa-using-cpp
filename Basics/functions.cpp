#include <iostream>
using namespace std;

void seperation()
{
    cout << endl
         << endl
         << endl
         << endl;
}

void findNthTermOfAP()
{
    cout << " General Form of nth term of an AP is A*n + B. Please enter the values of A and B: ";
    int a, b, n;
    cin >> a >> b;
    cout << "Enter which term you want to get from AP whose nth term can be written as A*n + B is: " << endl;
    cin >> n;
    cout << "Nth term of the AP is: " << (a * n + b) << endl;

    return;

    cout << "Kyonki main return ; ke baad likha hoon isliye main execute nahin hounga. " << endl;
}

int findNoOfSetBits(int number)
{
    int noOfSetBitsInNumber = 0;
    while (number)
    {
        if (number & 1)
        {
            noOfSetBitsInNumber++;
        }
        number >>= 1;
    }

    return noOfSetBitsInNumber;
}


int findNthTermOfFibonacciSeries(int n){
    int firstTerm = 0;
    int secondTerm = 1;

    if(firstTerm == n){
        return firstTerm;
    }
    else if(secondTerm == n){
        return secondTerm;
    }

    int nthTerm = 0;
    for(int i = 3; i <= n; i++){
        nthTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nthTerm;
    }
    return nthTerm;
}

int main()
{
    // Problem 1: Given AP's nth term is 3n + 7. Find nth Term in AP
    /*

    Anth = a + (n-1)*d
    Anth = (a - d) + n*d

    // 1st Term
    10 = (10 - 3) + 1*3
    10 = 7 + 3
    10 = 10

    // 2nd Term
    A2 = 3*2 + 7
    A2 = 6 + 7
    A2 = 13

    */
    findNthTermOfAP();

    // Problem 2: Given numbers a, b then find how many set bits are there in those numbers
    seperation();
    /*
    // Number of Set bits in a number can be calculated from its binary represetation
    10 in binary 1010,
    thus there are 2 set bits in this and therefore right shift by 1 and then count until the number is not becoming 0
    */
    cout << "Enter number of element for which we have to find Set Bits: ";
    int n = 0, totalNoOfSetBits = 0;
    cin >> n;

    int numberFromWhichWeHaveToFindSetBits[n];
    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> numberFromWhichWeHaveToFindSetBits[i];
    }

    for (int i = 0; i < n; i++)
    {
        totalNoOfSetBits += findNoOfSetBits(numberFromWhichWeHaveToFindSetBits[i]);
    }
    cout << "We have total " << totalNoOfSetBits << " Set bits. " << endl;

    // Problem 3: Find nth Fibonacci Series term
    seperation();
    /*
    // Nth term of Fibonacci can be found by calculating all the way upto Nth term
    0 1 1 2 3 5 8 13 21 34....

    */
   cout << "Fibonnaci Series is 0 1 1 2 3 5 8 13 21 34...." << endl;
   cout << "Enter which term you want to know: " << endl; 
   cin >> n;
   
    cout << n << "th term of Fibonacci Series is: " << findNthTermOfFibonacciSeries(n) << endl;

    seperation();
    
    return 0;
}
