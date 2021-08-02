#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, ans, cur;
pair<int, int> a[400000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> a[2 * i].first >> a[2 * i + 1].first;
        a[2 * i].second = 1;
        a[2 * i + 1].second = 0;
    }

    sort(a, a + 2*N);

    FOR(i, 2*N) {
        if(a[i].second) {
            cur++;
        } else {
            cur--;
        }

        ans = max(ans, cur);
    }

    cout << ans << endl;
}