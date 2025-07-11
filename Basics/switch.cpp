#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter age: ";
    cin >> age;

    switch (age) // Yahan Expression aayega
    {
        // case (age < 18): Expression nahin daal sakte values daal sakte hain
    case 18:
        cout << "You're 18 Years Old." << endl;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ; // Multiple Semi Colon lagane par bhi line end hoti hai isliye yahan koi error nahin aayega
        break;

    default:
        break;
    }

    // switch ke andar continue ka use nahin hota hai kyonki ye iteration ko skip karne ke liye hota hai aur switch mein iteration thode hi ho raha hai

    // switch (age)
    // {
    // // case (age < 18):
    //     case 20:
    //         cout << "You're 20 Years Old." << endl;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; // Multiple Semi Colon lagane par bhi line end hoti hai isliye yahan koi error nahin aayega
    //     continue;

    // default:
    //     break;
    // }

    // Note Break in 100, 50, 20, 1 using switch - Starts Here
    int totalAmountToBeBrokenIntoNotes;
    cout << "Enter the amount to be broken into 100, 50, 20, 1 notes: ";
    cin >> totalAmountToBeBrokenIntoNotes;

    int hundredRupeeNoteCount = totalAmountToBeBrokenIntoNotes / 100;

    totalAmountToBeBrokenIntoNotes = totalAmountToBeBrokenIntoNotes - hundredRupeeNoteCount * 100;

    int fiftyRupeeNoteCount = totalAmountToBeBrokenIntoNotes / 50;

    totalAmountToBeBrokenIntoNotes = totalAmountToBeBrokenIntoNotes - fiftyRupeeNoteCount * 50;

    int twentyRupeeNoteCount = totalAmountToBeBrokenIntoNotes / 20;

    totalAmountToBeBrokenIntoNotes = totalAmountToBeBrokenIntoNotes - twentyRupeeNoteCount * 20;

    int oneRupeeNoteCount = totalAmountToBeBrokenIntoNotes / 1;

    totalAmountToBeBrokenIntoNotes = totalAmountToBeBrokenIntoNotes - oneRupeeNoteCount * 1;

    cout << "We will need " << hundredRupeeNoteCount << ", " << fiftyRupeeNoteCount << ", " << twentyRupeeNoteCount << ", " << oneRupeeNoteCount << " number of notes of 100, 50, 20, 1 respectively." << endl;

    /*
    int totalAmountToBeBrokenIntoNotes;
    cout << "Enter the amount to be broken into 100, 50, 20, 1 notes: ";
    cin >> totalAmountToBeBrokenIntoNotes;

    int denominations[] = {100, 50, 20, 1};
    int noteCounts[4] = {0};

    for (int i = 0; i < 4; i++) {
        switch (denominations[i]) {
            case 100:
            case 50:
            case 20:
            case 1:
                noteCounts[i] = totalAmountToBeBrokenIntoNotes / denominations[i];
                totalAmountToBeBrokenIntoNotes %= denominations[i];
                break;
        }
    }

    cout << "We will need " << noteCounts[0] << ", " << noteCounts[1] << ", " << noteCounts[2] << ", " << noteCounts[3]
         << " number of notes of 100, 50, 20, 1 respectively." << endl;

    */

    // Note Break in 100, 50, 20, 1 using switch - Ends Here

    // Infinite Loop Ke andar switch
    while (1)
    {
        switch (age)
        {
        case 1:
            cout << "Infinite loop Ke andar hoon. " << endl;
            age--;    // Comment this line to go in Infinite loop
            continue; // Yahan loop hai isliye continue lag gaya aur koi error nahin aaya but we got stuck in infinite loop agar age ko minus nahin karte to

        default:
            exit(0);
        }
    }

    cout << "After Infinite Loop " << endl;

    return 0;
}