#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, Q, a, b, ind[200005], dist[200005];
vector<int> adj[200005];
vector<pair<int, int> > arr, tree(800010);



//**** ALL PARAMETERS ARE 0-INDEXED *****
//min from range a to b
int getmin(int a, int b) {
    a += N; b += N;
    pair<int, int> s = {INT_MAX, INT_MAX};
    while(a <= b) {
        if(a%2==1) s = min(s, tree[a++]);
        if(b%2==0) s = min(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s.first;
}

//initialize with another array a (size should be N)
void init(vector<pair<int, int> > a) {
    FOR2(i, N, 2*N) {
        tree[i] = a[i - N];
    }
    FOR2R(i, N-1, 1) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
}


void dfs(int src, int prev, int d) {
    arr.pb({d, src});
    ind[src] = arr.size()-1;
    dist[src] = d;
    for(int c : adj[src]) {
        if(c != prev) {
            dfs(c, src, d + 1);
            arr.pb({d, src});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> Q;

    FOR(i, N-1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1, 1);

    N = arr.size();
    init(arr);

    FOR(i, Q) {
        cin >> a >> b;
        cout << dist[a] + dist[b] - 2*getmin(min(ind[a], ind[b]), max(ind[a], ind[b])) << endl;
    }
}