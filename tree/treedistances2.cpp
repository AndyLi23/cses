#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, a, b, sub[200005];
long long dist[200005];
vector<int> adj[200005];

int dfs(int src, int pre, int dis) {
    int sum = 0;

    for(int c : adj[src]) {
        if(c != pre) {
            sum += dfs(c, src, dis+1);
        }
    }

    dist[1] += dis;

    sub[src] = sum + 1;
    return sum + 1;
}

void dfs_dist(int src, int pre) {
    if(src != 1) dist[src] = dist[pre] + (long long) sub[1] - (long long) 2*sub[src];

    for(int c : adj[src]) {
        if(c != pre) {
            dfs_dist(c, src);
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
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(1, -1, 0);

    dfs_dist(1, -1);

    FOR(i, N) {
        cout << dist[i + 1] << " ";
    }
}