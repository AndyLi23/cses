#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2e5;

string s;

unsigned long long fac[1000001];
map<int, int> m;

unsigned long long power(unsigned long long x, int y, int p) {
    unsigned long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p) {
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little theorem.
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
    // If n<r, then nCr should return 0
    if (n < r) return 0;
    // Base case
    if (r == 0) return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> s;

    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++) fac[i] = (fac[i - 1] * i) % MOD;

    FOR(i, s.length()) {
        m[s[i] - 97]++;
    }

    int N = s.length();
    long long ans = 1;

    FOR(i, 26) {
        if(m[i] != 0) {
            ans *= nCrModPFermat(N, m[i], MOD);
            ans %= MOD;
            N -= m[i];
        }
    }

    cout << ans << endl;
}