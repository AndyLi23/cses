#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, a, b;
vector<int> roads[100005];

bool visited[100005];
int from[100005];


//CYCLE IN DIRECTED GRAPH

int dfs(int cur, bool *rec) {
    if(!visited[cur]) {
        visited[cur] = rec[cur] = true;
        for(int v : roads[cur]) {
            if(!visited[v]) {
                from[v] = cur;
                int tmp = dfs(v, rec);
                if(tmp) return tmp;
            }
            if (rec[v]) {
                from[v] = cur;
                return v;
            }
        }
    }

    rec[cur] = false;
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
    }

    bool *rec = new bool[N + 5];

    FOR2(i, 1, N+1) {
        int temp = dfs(i, rec);
        if(temp) {
            vector<int> ans;

            int orig = temp;

            ans.push_back(temp);

            while(from[temp] != orig) {
                ans.push_back(from[temp]);
                temp = from[temp];
            }

            ans.push_back(orig);

            cout << ans.size() << endl;

            FOR2R(j, ans.size()-1, 0) {
                cout << ans[j] << " ";
            }

            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
}