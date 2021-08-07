#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, ans, a, b;
vector<int> adj[200005];
bool used[200005];

void dfs(int src, int pv) {
    for(int c : adj[src]) {
        if(c != pv) {
            dfs(c, src);
            if(!used[c] && !used[src]) {
                used[c] = used[src] = 1;
                ans++;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N-1) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    cout << ans << endl;
}