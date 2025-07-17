#include <iostream>
using namespace std;

class A
{
public:
    bool unlimitedMoney = true;
    bool unlimitedAchchai = true;
    string name;

    A()
    {
        cout << "Default constructor for A" << endl;
    }

    A(string name)
    {
        this->name = name;
        cout << "Bhai A Class ka Object with name: " << name << " ab paida ho gaya hai." << endl;
    }

    void achcheKaam()
    {
        cout << "Bhai main " << name << " hoon " << endl;
        cout << "Bhai A Class ka Object hoge to achche kaam to karoge." << endl;
    }

    void print()
    {
        cout << this->name << endl;
        cout << "Main to A class ka hoon yaar." << endl;
    }
};

class B : public A
{
private:
    int politicalPower = 1000;

public:
    bool kindness = true;

    // Agar Ye constructor hata denge to C ka object hi nahin ban payega
    B()
    {
        cout << "Default constructor for B" << endl;
    }

    B(string name)
    {
        this->name = name;
        cout << "Bhai B Class ka Object with name: " << name << " ab paida ho gaya hai." << endl;
    }

    void showPoliticalPower()
    {
        cout << "Raaste se uthwa lenge party ke log hamse bachke kahe ki Main to B class ka hoon yaar." << endl;
    }

    void print()
    {
        cout << this->name << endl;
        cout << "Main to B class ka hoon yaar." << endl;
    }
};

class C : public B
{
public:
    void print()
    {
        cout << this->name << endl;
        cout << "Main to C class ka hoon yaar." << endl;
    }
};

class D
{
public:
    int dadaGiri = 1000;

    void showDadaGiri()
    {
        cout << "Abe o Beta kantaap ghalega kahe ki Main to D class ka hoon yaar." << endl;
    }

    void print()
    {
        cout << "Main to D class ka hoon yaar." << endl;
    }
};

class E : public A, public D
{
public:
    bool mauj = true;

    void maujLo()
    {
        cout << "Juice peewanu carrom khelwanu majja ni life. " << endl;
    }
};

class F :

    public E,
    public C
/*

, public A
Agar Ye A ko bhi access karne ki koshish karenge baavjood iske ki C se B aur B se A pahle hi kar chuke hain to ek warning aayegi like

warning: direct base ‘A’ inaccessible in ‘F’ due to ambiguity [-Winaccessible-base]
  104 | class F : public E, public C, public A {
      |


*/
{
public:
    bool sabKuchh = true;

    void jalwaHaiHamara()
    {
        cout << "Sikka chale hai mere naam ka ikka bana doon main gulam ka. " << endl;
    }
};

int main()
{
    cout << "\n\nLet us declare A class's object: " << endl;
    A Dashrath("Dashrath");

    cout << "\n\nLet us declare B class's object: " << endl;
    B Ram; // or B Ram("Ram"); Both with work as parent class has default constructor thus child also have
    cout << endl;
    B Lakshman("Lakshman");

    // Go to B Class to see depth
    // C Lav = new B("Lav"); or C Lav; // Agar Parent class ka defaullt constructor nahin hain to child class ke andar constructor na hone par object nahin banaya ja sakta

    cout << "\n\nLet us declare C class's object: " << endl;
    C Lav;

    cout << "\n\nLet us declare D class's object: " << endl;
    D pahalwan;

    cout << "\n\nLet us declare E class's object: " << endl;
    E mastikhor;

    cout << "\n\nLet us declare F class's object: " << endl;
    F mastInsaan;

    cout << "\n\nSab Paida ho gaye ab lo maja: " << endl;

    mastInsaan.jalwaHaiHamara();
    // Ab kyonki hamne ismein A class ko E se bhi inherit kiya hai aur C se bhi isliye bhaiya yo error dega
    // mastInsaan.A::print();
    // mastInsaan.B::A::print();
    // mastInsaan.E::A::print();
    // mastInsaan.B::A::achcheKaam();
    // mastInsaan.E::A::achcheKaam();

    mastInsaan.E::name = "Mast Insaan";
    mastInsaan.B::name = "Mast Insaan";
    mastInsaan.E::D::print();
    mastInsaan.E::achcheKaam();
    mastInsaan.B::print();

    // Yaani ki ham aaram se A class ki cheejen chala sakte hain but A class ka use nahin kar sakte hain with this F class

    // Haalanki ye problem solve ki jaa sakti hai virtual inheritance se like:
    /*
    class A { ... };
    class B : virtual public A { ... };
    class D { ... };
    class E : virtual public A, public D { ... };
    class C : public B { ... };
    class F : public E, public C { ... };

    */
   
    // SEE THE EXTENDED VERSION OF THIS FILE virtualInheritance.cpp 
    // PLEASE NOTE: This is the extended version of the file inheritance.cpp 


    return 0;
}