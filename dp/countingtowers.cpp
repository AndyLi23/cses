#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, MOD=1000000007, q;
ll dp[1000001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    int mx = 1000000;

    dp[mx][0] = (ll) 1;
    dp[mx][1] = (ll) 1;

    FOR2R(i, mx-1, 0) {
        ll o1 = (dp[i + 1][1] + dp[i + 1][0] * 4) % MOD;
        ll o2 = (2 * dp[i + 1][1] + dp[i + 1][0]) % MOD;

        dp[i][0] = o1;
        dp[i][1] = o2;
    }

    cin >> N;

    FOR(i, N) {
        cin >> q;
        cout << ((int) (dp[mx - q + 1][0] + dp[mx - q + 1][1])) % MOD << "\n";
    }
}