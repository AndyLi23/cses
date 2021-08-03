#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, dp[1000005];

vector<int> getDigits(int i) {
    vector<int> digits;
    for (int j = 1; j <= i; j*=10) {
        digits.push_back((i / j) % 10);
    }
    return digits;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    dp[N] = 1;
    FOR2R(i, N, 0) {
        if(dp[i]) {
            for (int j = 1; j <= i; j*=10) {
                if((i / j) % 10 != 0) {
                    if(dp[i - ((i / j) % 10)]) dp[i - ((i / j) % 10)] = min(dp[i - ((i / j) % 10)], dp[i]+1);
                    else dp[i - ((i / j) % 10)] = dp[i]+1;
                }
            }
        }
    }

    cout << dp[0]-1 << endl;
}