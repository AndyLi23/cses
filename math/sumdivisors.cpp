#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

ll N, MOD = 1000000007, ans;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    for (ll i = 1, j; i <= N; i=j) {
        ll q = N / i;
        j = (N / q) + 1;

        ll x = j - i;
        ll y = i + j - 1;
        if(x%2==0) x /= 2;
        else y /= 2;
        x %= MOD, y %= MOD;
        ans = (ans + q % MOD * x % MOD * y % MOD) % MOD;
    }

    cout << ans << endl;
}