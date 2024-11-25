#include <iostream>
using namespace std;

void seperation(){
    cout << endl;
    cout << endl;
}

void lineBreak(){
    cout << endl;
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " " ;
    }
    lineBreak();
}

int main()
{
    int numbers[] = {1,2,3,4};

    seperation();
    cout << "Array elements are: ";
    printArray(numbers,4);
    seperation();


    // int even[4] = {0,2,4,6,8}; // Size se Extra elements dene par error aayega
    int even[4] = {0,2,4,6}; 

    cout << "Even Array elements are: ";
    printArray(even,4);
    seperation();


    int initializeMethodOne[4] = {0}; // Is tarah se sirf 0 se initialize kar sakte hain agar ham koi aur element daal de like 1 or 2 tab bhi pahle ko yaa jitne elements diye hain unko chhodkar baaki saare elements 0 se fill honge ye Khaas baat hai C++ mein
    int initializeMethodTwo[4] = {1};
    int initializeMethodThree[4] = {10};
    int initializeMethodFour[4] = {10,20};

    cout << "Initialize Method One Array elements are: ";
    printArray(initializeMethodOne,4);
    lineBreak();

    cout << "Initialize Method Two Array elements are: ";
    printArray(initializeMethodTwo,4);
    lineBreak();


    cout << "Initialize Method Three Array elements are: ";
    printArray(initializeMethodThree,4);
    lineBreak();


    cout << "Initialize Method Four Array elements are: ";
    printArray(initializeMethodFour,4);
    lineBreak();

    cout << "Method to initialize array with any number is using std::fill or std::fill_n functions" << endl;
    int sizeOfArray = 4;
    int nayiArray[sizeOfArray];
    fill_n(nayiArray,sizeOfArray,10);
    cout << "Nayi Array elements are: ";
    printArray(nayiArray,4);

    fill_n(nayiArray,sizeOfArray,20);
    cout << "Nayi Array elements are: ";
    printArray(nayiArray,4);

    fill(nayiArray,nayiArray + sizeOfArray,30);
    cout << "Nayi Array elements are: ";
    printArray(nayiArray,4);

    fill(nayiArray,nayiArray + sizeOfArray,40);
    cout << "Nayi Array elements are: ";
    printArray(nayiArray,4);

    seperation();
    
    return  0;
}
