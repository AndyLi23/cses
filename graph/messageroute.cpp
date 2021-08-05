#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, a, b;
vector<int> roads[100005];
pair<int, int> cur;
int from[100005];

void bfs(int start) {
    queue<pair<int, int> > q;

    q.push({start, -1});

    while(!q.empty()) {
        cur = q.front();
        q.pop();

        if(!from[cur.first]) {
            from[cur.first] = cur.second;
            if(cur.first == N) {
                return;
            }
            FOR(i, roads[cur.first].size()) {
                q.push({roads[cur.first][i], cur.first});
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

    FOR(i, M) {
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    bfs(1);

    if(!from[N]) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> ans;
        ans.push_back(N);
        while(N != 1) {
            ans.push_back(from[N]);
            N = from[N];
        }
        cout << ans.size() << endl;
        FOR2R(i, ans.size()-1, 0) {
            cout << ans[i] << " ";
        }
    }
}