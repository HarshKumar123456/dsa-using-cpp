#include <iostream>
using namespace std;

int gcd(int a, int b){
    cout << "Coming for " << a << " " << b << endl;
 
    if(a <= 0){
        return b;
    }

    if(b <= 0){
        return a;
    }

    if (a > b)
    {
        return gcd(a % b, b);
    }
    
    return gcd(a, b % a);
    
}

int main() {

    int a = 16, b = 9;
    cout << "GCD of " << a << ", " << b << " is " << gcd(a,b) << endl;

	cout << "We have taken TC: O( log (min(a,b)) ) and SC: O( log (min(a,b)) )" << endl;


    return 0;
}