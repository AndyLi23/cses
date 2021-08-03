#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(long long (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(long long (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(long long (i) = (b); (i) >= (a); --(i))

long long N, a[200000], T;

bool check(long long m) {
    long long total = 0;
    FOR(i, N) {
        total += m / a[i];
        if(total >= T) {
            break;
        }
    }
    return total >= T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> T;
    FOR(i, N) {
        cin >> a[i];
    }

    long long i = 0, j = 1e18, m, ans;
    while (i <= j) {
        m = (i+j)/2;
        if(check(m)) {
            ans = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }

    cout << ans << endl;
}