#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 1e5;

int N, M, a, b;
bool seen[MAXN][2];
vector<int> adj[MAXN][2];

void dfs(int v, int cur) {
    if(!seen[v][cur]) {
        seen[v][cur] = true;
        for(auto u : adj[v][cur]) dfs(u, cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b; a--; b--;
        adj[a][0].pb(b);
        adj[b][1].pb(a);
    }

    dfs(0, 0);
    FOR(i, N) {
        if(!seen[i][0]) {
            cout << "NO\n" << 1 << " " << i+1 << endl;
            return 0;
        }
    }

    dfs(0, 1);
    FOR(i, N) {
        if(!seen[i][1]) {
            cout << "NO\n" << i+1 << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES\n";
}