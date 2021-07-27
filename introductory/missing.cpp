#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, temp;
bool m[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;
    FOR(i, N-1) {
        cin >> temp;
        m[temp] = true;
    }

    FOR2(i, 1, N+1) {
        if(!m[i]) {
            cout << i << endl;
            break;
        }
    }
}