#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2e5;

int N, dp[500][200000];
int a[6] = {5, 10, 6, 5, 10, 6}; //available numbers

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    N = 6;

    int M = 20; //target number

    dp[0][0] = 1;
    FOR2(i, 1, N+1) {
        FOR(j, M+1) {
            dp[i][j] = dp[i - 1][j];
            int left = j - a[i-1];
            if(left >= 0) dp[i][j] = (dp[i-1][left] + dp[i][j])%MOD;
        }
    }

    cout << dp[N][M] << endl; //ways to get to M using N elements
}