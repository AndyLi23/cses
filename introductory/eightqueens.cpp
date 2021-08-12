#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2e5;

string s;
bool board[8][8];
int cur[8], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    FOR(i, 8) {
        cin >> s;
        FOR(j, 8) {
            if(s[j] == '*') board[i][j] = true;
        }
        cur[i] = i;
    }

    do {
        vector<bool> diagonals(16, false), diagonals2(16, false);

        bool good = true;

        FOR(i, 8) {
            if(board[i][cur[i]] || diagonals[i-cur[i]+7] || diagonals2[cur[i]+i]) {
                good = false;
                break;
            }
            diagonals[i - cur[i] + 7] = true;
            diagonals2[cur[i] + i] = true;
        }

        if(good) ans++;
    } while (next_permutation(cur, cur + 8));

    cout << ans << endl;
}