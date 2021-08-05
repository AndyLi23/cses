#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, a, b;
vector<int> graph[100005];
int team[100005];

bool bfs(int start) {
    queue<pair<int, int> > q;

    q.push({start, 0});

    while(!q.empty()) {
        int cur = q.front().first;
        int curteam = q.front().second;
        q.pop();

        if(!team[cur]) {
            team[cur] = curteam % 2 + 1;
            FOR(i, graph[cur].size()) {
                q.push({graph[cur][i], curteam % 2 + 1});
            }
        } else {
            if(team[cur] == (curteam+1) % 2 + 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    FOR(i, N) {
        if(!team[i+1]) {
            if(!bfs(i+1)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    FOR(i, N) {
        cout << team[i + 1] << " ";
    }
}