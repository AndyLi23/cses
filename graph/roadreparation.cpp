#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(weight==e.weight) return dest<e.dest;
        else return weight<e.weight;
    }
};

int N, M, a, b, c;
vector<Edge> graph[100000];

int seen[100000];
int seen_num = 0;

class comp { public: bool operator() (Edge e1, Edge e2) { return e2 < e1; } };

priority_queue < Edge, vector<Edge>, comp> pq;

long long prims(vector<Edge> graph[]) {
    pq.push(Edge{0, N-1});

    long long ans = 0;
    int cost, cur;
    Edge temp;

    while (pq.empty() == false && seen_num < N) {
        temp = pq.top();
        pq.pop();

        cost = temp.weight;
        cur = temp.dest;

        if(seen[cur] == 0) {
            seen[cur] = 1;
            ans += cost;
            seen_num++;

            FOR(i, graph[cur].size()) {
                pq.push(graph[cur][i]);
            }
        }
    } 
    return ans;
}
//--------------------------------------------

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b >> c;
        a--; b--;

        graph[a].pb({c, b});
        graph[b].pb({c, a});
    }

    long long ans = prims(graph);

    if(seen_num < N) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}