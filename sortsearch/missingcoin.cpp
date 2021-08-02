#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

long long N, a[200000], s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> a[i];
    }

    sort(a, a + N);

    FOR(i, N) {
        if (a[i] > s+1) {
            cout << s + 1;
            return 0;
        } else {
            s += a[i];
        }
    }
    cout << s + 1;
}