#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, grid[1000][1000], MOD = 1000000007;
string s;

int get(int i, int j) {
    int ans = 0;
    if(i > 0) {
        ans += max(0, grid[i - 1][j]);
    }
    if(j > 0) {
        ans = (ans + max(0, grid[i][j-1])) % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> s;
        FOR(j, N) {
            if(s[j] == '*') {
                grid[i][j] = -1;
            }
        }
    }
    if(grid[0][0] != -1) {
        grid[0][0] = 1;
    }
    FOR(i, N) {
        FOR(j, N) {
            if(grid[i][j] != -1 && !(i == 0 && j == 0)) {
                grid[i][j] = get(i, j);
            }
        }
    }
    cout << max(0, grid[N - 1][N - 1]) << endl;
}