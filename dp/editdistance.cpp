#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2e5;

string s1, s2;
int dp[5005][5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> s1 >> s2;

    FOR(i, s1.length()+1) {
        dp[i][0] = i;
    }

    FOR(i, s2.length()+1) {
        dp[0][i] = i;
    }

    FOR2(i, 1, s1.length()+1) {
        FOR2(j, 1, s2.length()+1) {
            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + !(s1[i-1]==s2[j-1])));
        }
    }

    cout << dp[s1.length()][s2.length()] << endl;
}