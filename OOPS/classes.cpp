#include <iostream>
#include <cstring>
using namespace std;

class Hero
{
public:
    int value;
    int health;
    string name;
    char *likes;
    int *gameScores;
    static int timeToComplete;
    // Hero()
    // {
    //     cout << "Un-Parameterized Constructor is called." << endl;
    // }
    Hero(int value)
    {
        this->name = "default";
        this->value = value;
        (*this).health = 100;
        this->likes = new char[100];
        this->gameScores = new int[10];
        cout << "Parameterized Constructor with 1 parameter is called." << endl;
    }

    Hero(int value, int health)
    {
        this->name = "default";
        this->value = value;
        (*this).health = health;
        this->likes = new char[100];
        this->gameScores = new int[10];
        cout << "Parameterized Constructor with 2 parameter is called." << endl;
    }

    Hero(int value, int health, string name)
    {
        this->name = name;
        this->value = value;
        (*this).health = health;
        this->likes = new char[100];
        this->gameScores = new int[10];
        cout << "Parameterized Constructor with 3 parameter is called." << endl;
    }

    // Custom Copy Constructor
    // Hero(Hero &jisseCopyKarniHai) {
    //     cout << "Copy Constructor Called...." << endl;
    //     this->name = jisseCopyKarniHai.name;
    //     this->health = jisseCopyKarniHai.health;
    //     this->value = jisseCopyKarniHai.value;

    //     // Deep Copy
    //     int *kshanik = new int[10];
    //     for (int i = 0; i < 10; i++)
    //     {
    //         kshanik[i] = jisseCopyKarniHai.gameScores[i];
    //     }
    //     this->gameScores = kshanik;

    //     char *kuchhPalKeLiye = new char[100];
    //     strcpy(kuchhPalKeLiye, jisseCopyKarniHai.likes);
    //     this->likes = kuchhPalKeLiye;
    // }

    void setLikes(char likes[])
    {
        strcpy(this->likes, likes);
    }

    void print()
    {
        cout << "Name: " << this->name << endl;
        cout << "Value: " << this->value << endl;
        cout << "Health: " << this->health << endl;
        cout << "Likes: " << this->likes << endl;
        cout << "Address of likes: " << &(this->likes) << endl;
        cout << "Game's Scores: ";
        for (int i = 0; i < 10; i++)
        {
            cout << this->gameScores[i] << " ";
        }
        cout << endl;

        cout << endl;
    }

    // Static Methods
    static void tellRemainingTime() {
        cout << "Bro! Time remaining is: " << timeToComplete << endl;
        return ; 
    }

    static int giveRemainingTime() {
        cout << "Bro! Time remaining is: " << timeToComplete << endl;
        return timeToComplete;
    }

    static void changeTimeToComplete(int plusTime) {
        timeToComplete += plusTime;
        cout << "Bro! Time Added and now Time remaining is: " << timeToComplete << endl;
        return;
    }

    ~Hero()
    {
        cout << endl
             << endl
             << "Destructor is called for the: " << endl;
        this->print();
        cout << "Main Hoon Destructor Free Karwa doonga memory ne." << endl;
    }
};

class A
{
    // Greedy Alignment : Increasing yaa Decreasing order of size mein lagana taaki padding kam ho
    char c;
    char d;
    int i;
    double l;
};

class B
{
    // Yahan padding hogi to align the char with int +3 padding phir int ke neeche  wala char align with int +3 padding phir last mein kyonki double hai isliye 8 ka multiple hona chahiye memory alloted isliye before double char (1byte + 3byte = 4byte) phir int (4byte) phir char(1byte + 3byte = 4byte) ab memory alloted 12byte but we have 8byte double thus starting 8byte will have char c and int i and next char with 3byte padding will have +4 byte to align with double to ab total size is 24 byte
    char c;
    int i;
    char d;
    double l;
};

class C
{
    // Greedy Alignment : Increasing yaa Decreasing order of size mein lagana taaki padding kam ho
    double l;
    int i;
    char c;
    char d;
};

void lineBreak()
{
    cout << endl
         << endl;
    return;
}

// Initialization of Static Members
int Hero::timeToComplete = 10;

int main()
{
    // Yo yahan Error dega bhai
    // int Hero::timeToComplete = 10;

    cout << "Hi " << endl;
    Hero harsh(100);
    cout << "Hello" << endl;
    cout << endl;

    Hero abc(100);
    abc = harsh; // Or We could have done like Hero abc(harsh);
    char likes[11] = "Everything";
    harsh.setLikes(likes);

    cout << "Before: " << endl;
    harsh.print();
    abc.print();

    harsh.name = "Harsh"; // Since this is string it is not like an array and thus it used to changed individually for each instance of Hero Class but when we do some changes into the array then it does reflect the changes in both instances from one which we have copied and to which we are copying
    harsh.likes[3] = 'S'; // This will affect both because shallow copy
    abc.likes[1] = 'h';   // This will affect both because shallow copy
    harsh.gameScores[0] = 100;
    abc.gameScores[1] = 100;
    lineBreak();

    cout << "After: " << endl;
    harsh.print();
    abc.print();

    lineBreak();
    cout << "Greedy Alignment & Padding type things: " << endl;
    A a;
    B b;
    C c;

    cout << "Size of a: " << sizeof(a) << endl;
    cout << "Size of b: " << sizeof(b) << endl;
    cout << "Size of c: " << sizeof(c) << endl;

    lineBreak();
    cout << "Now here is time to do some dynamic creation of the objects: " << endl;
    Hero *paul = new Hero(100, 100, "Paul");

    cout << "Bhaiya ab to dynamic allocation ho gaya. " << endl;
    char *paulLikes = new char[sizeof(char) * 5];
    paulLikes[0] = 'P';
    paulLikes[1] = 'A';
    paulLikes[2] = 'U';
    paulLikes[3] = 'L';
    paulLikes[4] = '@';
    paulLikes[5] = '3';
    paulLikes[6] = '4';

    paul->likes = paulLikes;
    paul->print();
    lineBreak();


    // Static Data Members ne statically hi access karna good practice hove se bhai mere, however we can access them via objects also as they belongs to class and even can be accessed without creating the objects then obviously we can do access with the objects 
    harsh.timeToComplete = 20; // Not Recommended Practice
    Hero::timeToComplete = 10; // Recommended Practice
    cout << "Bhai game khatam hone mein time bacha hai bas " << Hero::timeToComplete << endl;

    Hero::tellRemainingTime();
    int timeRemains = Hero::giveRemainingTime();
    cout << "Bhai time remains: " << timeRemains << endl;
    Hero::changeTimeToComplete(10);
    cout << "Bhai game khatam hone mein time bacha hai bas " << Hero::timeToComplete << endl;



    // Dynamic Objects ke kaje lalla manually free kare padi memory
    delete paul; 

    return 0;
}