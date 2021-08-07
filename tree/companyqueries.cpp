#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, Q, a, b, ancestor[200005][30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> Q;

    FOR(i, N-1) {
        cin >> ancestor[i+2][1];
    }

    int cur = 2;

    for (int i = 2; i < N; i *= 2) {
        FOR2(j, 1, N+1) {
            ancestor[j][cur] = ancestor[ancestor[j][cur-1]][cur-1];
        }
        cur++;
    }


    /*FOR2(i, 1, 4) {
        FOR2(j, 1, N+1) {
            cout << ancestor[j][i] << " ";
        }
        cout << endl;
    }*/

    FOR(i, Q) {
        cin >> a >> b;

        int cur = 1;
        int counter = 1;
        while(cur <= b) {
            cur *= 2;
            counter++;
        }

        while(cur) {
            if(cur <= b) {
                a = ancestor[a][counter];
                b -= cur;
            }
            cur /= 2;
            counter--;
        }

        if(a) cout << a << " ";
        else cout << -1 << " ";
    }
}