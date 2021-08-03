#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, X, dp[200000], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> X;

    vector<int> h(N), s(N);
    FOR(i, N) cin >> h[i];
    FOR(i, N) cin >> s[i];

    FOR(i, N) {
        FOR2R(j, X-h[i], 0) {
            if(dp[j] || j == 0) {
                dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
                ans = max(ans, dp[j + h[i]]);
            }
        }
    }

    cout << ans << endl;
}