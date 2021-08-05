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

int bfs(int start) {
    stack<pair<int, int> > q;

    q.push({start, -1});

    while(!q.empty()) {
        cur = q.top();
        q.pop();

        if(!from[cur.first]) {
            from[cur.first] = cur.second;
            FOR(i, roads[cur.first].size()) {
                if(roads[cur.first][i] != cur.second) {
                    q.push({roads[cur.first][i], cur.first});
                }
            }
        } else {
            from[cur.first] = cur.second;
            return cur.first;
        }
    }

    return 0;
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

    FOR(i, N) {
        if(!from[i+1]) {
            int temp = bfs(i + 1);
            if(temp) {

                vector<int> ans;

                int orig = temp;

                ans.push_back(temp);

                while(from[temp] != orig) {
                    ans.push_back(from[temp]);
                    temp = from[temp];
                }
                
                cout << ans.size()+1 << endl;

                cout << orig << " ";

                FOR2R(i, ans.size()-1, 0) {
                    cout << ans[i] << " ";
                }


                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}