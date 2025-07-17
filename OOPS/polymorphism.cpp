#include <iostream>
using namespace std;


// Compile Time Polymorphism Mane ki Functional Overloading, Operator overloading jo compile time par hi bata degi ki yo scene ka different matlab hai

// Run Time Polymorphism Mane Method Overriding type cheejen jo run time par hi pata chalengi based on context

class Animal {
    public: 

        void walk() {
            cout << "Animal is Walking....." << endl;
        }

        // Function Overloading
        void speak() {
            cout << "Animal Is Speaking...." << endl;
        }

        void speak(string name) {
            cout << name << " Animal Is Speaking...." << endl;
        }

        int speak(int value) {
            cout << "Animal Is Speaking...." << endl;
            return value;
        }

        // Operator Overloading
        void operator() () {
            cout << "Yo Bro! This () is Overloaded...." << endl;
        }

        void operator++ (int) {
            cout << "Yo Bro! This Animal++ is Overloaded...." << endl;
        }

        void operator++ () {
            cout << "Yo Bro! This ++Animal is Overloaded...." << endl;
        }

        // This will also work
        // void operator+ (Animal a) {
        //     this->speak();
        //     a.speak();

        //     cout << "Yo Bro! This Animal + Animal is Overloaded...." << endl;
        // }

        void operator+ (Animal &a) {
            this->speak("Kutta");
            a.speak("Billi");

            cout << "Yo Bro! This Animal + Animal is Overloaded...." << endl;
        }
        
};


class Dog : public Animal {
    public: 
        // Method Overriding
        void walk() {
            cout << "Dog is Walking....." << endl;
        }
};


int main() {
    Animal kutta;
    kutta();
    kutta++;
    ++kutta;
    kutta + kutta;


    cout << endl << endl;


    Dog dog;
    dog.walk();

    return 0;
}
