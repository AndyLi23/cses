#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, a, b;
bool seen[100005];
vector<int> roads[100005];
vector<int> ans;

void dfs(int cur) {
    if(!seen[cur]) {
        seen[cur] = true;
        FOR(i, roads[cur].size()) {
            dfs(roads[cur][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    dfs(1);

    FOR2(i, 1, N+1) {
        if(!seen[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }

    cout << ans.size() << endl;
    FOR(i, ans.size()) {
        cout << 1 << " " << ans[i] << endl;
    }
}