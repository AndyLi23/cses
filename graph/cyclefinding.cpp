#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, a, b, cur, path[5000];
long long dist[5000];
bool bad[5000], seen[5000];

int BellmanFord(int source, vector<tuple<int, int, int> > e) {

    FOR(i, N) {
        dist[i] = (long long) 1e16;
    }

    dist[source] = 0;
    path[source] = -1;

    FOR(i, N) {
        for(auto [a,b,w] : e) {
            if((long long) dist[b] > (long long) dist[a] + (long long) w) {
                dist[b] = (long long) dist[a] + (long long) w;
                path[b] = a;
                if(i == N-1 && !bad[a] && !bad[b]) {
                    //detect cycles on path from source to N-1
                    return a;
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;

    vector<tuple<int, int, int> > e;

    FOR(i, M) {
        cin >> a >> b >> cur;
        a--; b--;
        e.push_back({a, b, cur});
    }

    int ans = BellmanFord(0, e);

    if(ans != -1) {
        cout << "YES\n";
        vector<int> trace;

        seen[ans] = true;

        while(!seen[path[ans]] && path[ans] != -1) {
            trace.push_back(path[ans] + 1);
            ans = path[ans];
            seen[ans] = true;
        }

        trace.push_back(path[ans] + 1);
        trace.insert(trace.begin(), path[ans] + 1);

        FOR2R(i, trace.size()-1, 0) {
            cout << trace[i] << " ";
        }
    } else {
        cout << "NO\n";
    }
}