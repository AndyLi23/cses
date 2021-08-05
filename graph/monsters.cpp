#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M;
string s;
int monster_dist[1000][1000], player_dist[1000][1000];
bool grid[1000][1000];
queue< pair<int, int> > q;
pair<int, int> playerpos, from[1000][1000];

void check(int pi, int pj, int i, int j) {
    if(i >= 0 && j >= 0 && i < N && j < M && grid[i][j] && !monster_dist[i][j]) {
        monster_dist[i][j] = monster_dist[pi][pj] + 1;
        q.push({i, j});
    }
}

void monster_bfs() {
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        check(i, j, i + 1, j);
        check(i, j, i - 1, j);
        check(i, j, i, j + 1);
        check(i, j, i, j - 1);
    }
}

void player_check(int pi, int pj, int i, int j) {
    if(i >= 0 && j >= 0 && i < N && j < M && grid[i][j] && (player_dist[pi][pj]+1 < monster_dist[i][j] || monster_dist[i][j] == 0) && !player_dist[i][j]) {
        player_dist[i][j] = player_dist[pi][pj] + 1;
        q.push({i, j});
        from[i][j] = {pi, pj};
    }
}

pair<int, int> player_bfs() {
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();

        if(i == 0 || i == N-1 || j == 0 || j == M-1) {
            return {i, j};
        }

        player_check(i, j, i + 1, j);
        player_check(i, j, i - 1, j);
        player_check(i, j, i, j + 1);
        player_check(i, j, i, j - 1);
    }

    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR(i, N) {
        cin >> s;
        FOR(j, M) {
            if(s[j] != '#') {
                grid[i][j] = true;
            }
            if(s[j] == 'M') {
                monster_dist[i][j] = 1;
                q.push({i, j});
            }
            if(s[j] == 'A') {
                playerpos = {i, j};
            }
        }
    }

    //BFS with all monster positions in queue

    monster_bfs();

    //BFS player, if player dist >= monster dist then impossible, keep track of from to retrace

    q.push(playerpos);
    player_dist[playerpos.first][playerpos.second] = 1;
    pair<int, int> ans = player_bfs();

    vector<char> path;
    if(ans.first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        while(!(ans.first == playerpos.first && ans.second == playerpos.second)) {
            pair<int, int> pre = from[ans.first][ans.second];
            if(pre.first == ans.first-1) {
                path.push_back('D');
            } else if (pre.first == ans.first+1) {
                path.push_back('U');
            } else if(pre.second == ans.second-1) {
                path.push_back('R');
            } else if (pre.second == ans.second+1) {
                path.push_back('L');
            }

            ans = pre;
        }

        cout << path.size() << endl;

        FOR2R(i, path.size()-1, 0) {
            cout << path[i];
        }
    }
}