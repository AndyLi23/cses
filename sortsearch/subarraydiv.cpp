#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

ll N, ps, ans, a[200000];
map <ll, int > sums;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;

    FOR(i, N) {
        cin >> a[i];
    }
    sums[0] = 1;
    FOR(i, N) {
        ps += a[i];

        int mod = ps % N;
        if(mod < 0) mod += N;

        ans += sums[mod];

        sums[mod]++;
    }

    cout << ans << endl;
}