#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2e5;

int w, h, dp[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> w >> h;

    FOR(i, w+1) {
        FOR(j, h+1) {
            if (i==j) dp[i][j] = 0;
            else {
                dp[i][j] = INT_MAX;
                FOR2(k, 1, i/2+1) {
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
                }
                FOR2(k, 1, j/2+1) {
                    dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
                }
            }
        }
    }

    cout << dp[w][h] << endl;
}