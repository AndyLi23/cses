#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, ans;
bool a[1000][1000];

void dfs(int i, int j) {
    if(i>=0 && i < N && j>=0 && j < M && a[i][j]) {
        a[i][j] = false;
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    string s;

    FOR(i, N) {
        cin >> s;
        FOR(j, M) {
            if(s[j] == '.') {
                a[i][j] = true;
            }
        }
    }

    FOR(i, N) {
        FOR(j, M) {
            if(a[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;
}