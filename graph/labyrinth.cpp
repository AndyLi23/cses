#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M;
bool a[1000][1000];
pair<int, int> start, end_;
pair<int, int> cur;
char path[1000][1000], t;

void bfs(int i, int j) {
    queue<pair<pair<int, int>, char> > q;

    q.push({{i, j}, 'A'});

    while(!q.empty()) {
        cur = q.front().first;
        t = q.front().second;
        q.pop();
        int i = cur.first, j = cur.second;

        if(i == end_.first && j == end_.second) {
            path[i][j] = t;
            return;
        } else if (i >= 0 && i < N && j >= 0 && j < M && a[i][j]) {
            a[i][j] = false;
            path[i][j] = t;
            q.push({{i + 1, j}, 'D'});
            q.push({{i - 1, j}, 'U'});
            q.push({{i, j - 1}, 'L'});
            q.push({{i, j + 1}, 'R'});
        }
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    string s;

    FOR(i, N) {
        cin >> s;
        FOR(j, M) {
            if(s[j] != '#') {
                a[i][j] = true;
            }
            if(s[j] == 'A') {
                start = {i, j};
            } else if (s[j] == 'B') {
                end_ = {i, j};
            }
        }
    }

    bfs(start.first, start.second);

    int i = end_.first, j = end_.second;
    if(path[i][j] == 'D' || path[i][j] == 'U' || path[i][j] == 'L' || path[i][j] == 'R') {
        cout << "YES\n";

        vector<char> v;
        while(path[i][j] != 'A') {
            v.push_back(path[i][j]);
            if(path[i][j] == 'D') {
                i--; 
            } else if (path[i][j] == 'U') {
                i++;
            } else if (path[i][j] == 'L') {
                j++;
            } else {
                j--;
            }
        }

        cout << v.size() << "\n";
        FOR2R(k, v.size()-1, 0) {
            cout << v[k];
        }
    }
    else
    {
        cout << "NO\n";
    }
}