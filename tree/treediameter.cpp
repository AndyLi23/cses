#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, a, b, leaf[200005], maxlength[200005], ans;
vector<int> adj[200005];

void dfs(int src, int pre) {
    int max1 = 0, max2 = 0, temp = 0;

    for(int c : adj[src]) {
        if(pre != c) {
            dfs(c, src);
            leaf[src] = max(leaf[src], leaf[c]+1);

            if(leaf[c] > max1) {
                temp = max1;
                max1 = leaf[c];
                max2 = temp;
            } else if (leaf[c] > max2) {
                max2 = leaf[c];
            }
        }
    }
    
    if(adj[src].size() > 2) {
        maxlength[src] = max1 + max2 + 2;
    } else if (adj[src].size() > 1) {
        maxlength[src] = max1 + 1;
    }

    ans = max(ans, maxlength[src]);
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

    adj[1].pb(1);

    dfs(1, 1);

    cout << ans << endl;
}