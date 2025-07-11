#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

long long modExp(long long base, int exp, int mod) {
    if (exp == 0) return 1LL;

    long long half = modExp(base, exp / 2, mod);
    long long result = (half * half) % mod;

    if (exp % 2 == 0) {
        return result;
    } else {
        return (base % mod * result) % mod;
    }
}


// This overflows the long long range as 
// multiplying can go outside range of long long 
// and before we apply the mod it gone break
// long long modExp(long long base, int exp, int mod) {
    
//     if(exp == 0) {
//         return 1LL;
//     } 

//     long long result = modExp(base, exp/2, mod) % mod;

//     if (exp % 2 == 0) {
//         return (result * result) % mod;
//     }

//     return ( base * ( result * result ) % mod ) % mod;
// }

// long long modExp(long long base, int exp, int mod) {
//     long long result = 1;
//     while (exp > 0) {
//         if (exp % 2 == 1) {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return result;
// }

int nthTermOfGP(int N, int A, int R) {
    if (A == 0 || R == 0) return 0;

    long long r_val = modExp(R, N - 1, mod);
    long long ans = (A * r_val) % mod;

    return ans;
}


int main () {
    int firstTerm, commonRatio, nthTerm;
    cout << "Please enter the firstTerm, commonRatio, nthTerm's No. : "; 
    cin >> firstTerm >> commonRatio >> nthTerm;

    cout << "Nth term of GP is: " << nthTermOfGP(nthTerm, firstTerm, commonRatio) << endl; 

	cout << "We have taken TC: O( log (n) ) and SC: O( log (n) )" << endl;

    
    return 0;
}
