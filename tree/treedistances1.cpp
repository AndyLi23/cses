#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, a, b, dis[200005][2];
vector<int> adj[200005];

pair<int, int> mx;

void dfs(int src, int pre, int dist) {
    if(dist > mx.second) {
        mx.first = src;
        mx.second = dist;
    }

    for(int c : adj[src]) {
        if(c != pre) {
            dfs(c, src, dist + 1);
        }
    }
}

void dfs_dist(int src, int pre, int dist, int ind) {
    dis[src][ind] = dist;
    for(int c : adj[src]) {
        if(c != pre) {
            dfs_dist(c, src, dist + 1, ind);
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
    int da = mx.first;
    mx.second = 0;
    dfs(da, -1, 0);
    int db = mx.first;

    dfs_dist(da, -1, 0, 0);
    dfs_dist(db, -1, 0, 1);

    FOR(i, N) {
        cout << max(dis[i+1][0], dis[i+1][1]) << " ";
    }
}