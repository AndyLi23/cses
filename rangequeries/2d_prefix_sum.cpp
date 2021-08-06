#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, Q, forest[1005][1005], a1, b1, a2, b2;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> Q;

    FOR(i, N) {
        cin >> s;
        FOR(j, N) {
            if(s[j] == '*') {
                forest[i+1][j+1] = 1;
            }
        }
    }

    FOR2(i, 1, N) {
        forest[1][i+1] += forest[1][i];
        forest[i+1][1] += forest[i][1];
    }

    FOR2(i, 1, N) {
        FOR2(j, 1, N) {
            forest[i+1][j+1] += forest[i][j+1] + forest[i+1][j] - forest[i][j];
        }
    }

    /*FOR(i, N) {
        FOR(j, N) {
            cout << forest[i+1][j+1] << " ";
        }
        cout << endl;
    }*/

    FOR(i, Q) {
        cin >> a1 >> b1 >> a2 >> b2;
        cout << forest[a2][b2] + forest[a1-1][b1-1] - forest[a2][b1-1] - forest[a1-1][b2] << endl;
    }
}