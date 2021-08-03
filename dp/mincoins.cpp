#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, X, dp[2000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> X;

    vector<int> coins(N);

    FOR(i, N) cin >> coins[i];

    dp[0] = 1;

    FOR(i, X) {
        if(dp[i]) {
            for(int c : coins) {
                if(dp[i+c]) dp[i + c] = min(dp[i + c], dp[i] + 1);
                else dp[i+c] = dp[i]+1;
            }
        }
    }

    cout << dp[X]-1 << endl;
}