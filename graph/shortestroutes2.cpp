#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, Q, a, b;

long long dist[500][500], c;


void fw() {
    FOR(i, N) {
        FOR(j, N) {
            if (i==j) dist[i][j]=0;
            else if (!dist[i][j]) dist[i][j] = 1e18;
        }
    }
    FOR(k, N) {
        FOR(i, N) {
            FOR(j, N) {
                if(dist[i][k] != 1e18 && dist[k][j] != 1e18) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M >> Q;

    FOR(i, M) {
        cin >> a >> b >> c; a--; b--;
        if(dist[a][b] == 0) {
            dist[a][b] = dist[b][a] = c;
        }    
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    fw();

    FOR(i, Q) {
        cin >> a >> b; a--; b--;
        if(dist[a][b] == 1e18) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }
}