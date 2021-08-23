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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    int M = (N * (N + 1)) / 2;

    if(M%2) {
        cout << 0 << endl;
        return 0;
    }

    M /= 2;

    dp[0][0] = 1;
    FOR2(i, 1, N) {
        FOR(j, M+1) {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if(left >= 0) dp[i][j] = (dp[i-1][left] + dp[i][j])%MOD;
        }
    }

    cout << dp[N-1][M] << endl;
}