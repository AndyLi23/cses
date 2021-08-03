#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N;
long long a[200000], total, mx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;
    FOR(i, N) {
        cin >> a[i];
        total += a[i];
        mx = max(mx, a[i]);
    }

    if(mx > total-mx) {
        cout << mx * 2 << endl;
    } else {
        cout << total << endl;
    }
}