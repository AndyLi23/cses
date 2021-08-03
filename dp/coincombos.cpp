#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, X, counter[2000500], MOD=1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> X;

    vector<int> coins(N);

    FOR(i, N) cin >> coins[i];
    counter[0] = 1;

    FOR(i, X) {
        if(counter[i]) {
            for(int j : coins) {
                counter[i + j] = (counter[i] + counter[i + j]) % MOD;
            }
        }
    }

    cout << counter[X] << endl;
}