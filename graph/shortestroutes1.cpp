#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, a, b, cur;
bool seen[100000];
long long dist[100000];

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(dest==e.dest) return weight<e.weight;
        else return dest<e.dest;
    }
};

priority_queue<pair<long long, int> > q;

void djikstras(int src, vector<Edge> graph[]) {
    FOR(i, N) {
        dist[i] = 1e18;
    }
    dist[src] = 0;
    q.push({0, src});

    while(!q.empty()) {
        cur = q.top().second;
        q.pop();

        if(seen[cur]) continue;
        seen[cur] = true;

        for(Edge u : graph[cur]) {
            if(dist[cur]+u.weight < dist[u.dest]) {
                dist[u.dest] = dist[cur] + u.weight;
                q.push({-dist[u.dest], u.dest});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    vector<Edge> graph[N];

    FOR(i, M) {
        cin >> a >> b >> cur;
        a--; b--;
        graph[a].push_back({cur, b});
    }

    djikstras(0, graph);

    FOR(i, N) {
        cout << dist[i] << " ";
    }
}