#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, X, l, r, a[200000], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> X;

    l = 0;
    r = N - 1;

    FOR(i, N) {
        cin >> a[i];
    }

    sort(a, a + N);

    while(l <= r) {
        if(a[l]+a[r] > X) {
            r--;
            ans++;
        } else {
            r--;
            l++;
            ans++;
        }
    }

    cout << ans << endl;
}