#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, x[100000], dp[100000][105];
int MOD = 1000000007;

int get(int i, int j) {
    int ans = 0;
    if(j > 1) {
        ans += dp[i - 1][j - 1];
    }
    if (j < M) {
        ans = (ans + dp[i - 1][j + 1]) % MOD;
    }
    return (ans + dp[i - 1][j]) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR(i, N) {
        cin >> x[i];
    }

    if(x[0] == 0) {
        FOR2(v, 1, M+1) {
            dp[0][v] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }

    FOR2(i, 1, N) {
        if(x[i] == 0) {
            FOR2(j, 1, M+1) {
                dp[i][j] = get(i, j);
            }
        } else {
            dp[i][x[i]] = get(i, x[i]);
        }
    }

    int total = 0;

    /*FOR(i, N) {
        FOR2(j, 1, M+1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    FOR2(i, 1, M+1) {
        total = (total + dp[N - 1][i])%MOD;
    }

    cout << total << endl;
}