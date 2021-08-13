#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const ll MOD = 1000000007;
const int MAXN = 2e5;

ll h[1000000], p[1000000];
string s, t;

const ll A = 7;
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> s >> t;

    int N = s.length(), M = t.length();

    FOR(i, N) s[i]-=96;
    FOR(i, M) t[i]-=96;

    h[0] = s[0];
    p[0] = 1;

    FOR2(i, 1, N) {
        h[i] = ((h[i - 1] * A + s[i]) % MOD + MOD)%MOD;
        p[i] = ((p[i - 1] * A) % MOD + MOD) % MOD;
    }

    ll thash = t[0];
    FOR2(i, 1, M) {
        thash = ((thash * A + t[i]) % MOD + MOD) % MOD;
    }

    //cout << thash << endl;

    FOR(i, N-M+1) {
        if(i) {
            ll hash = ((h[i+M-1] - h[i-1]*p[M])%MOD + MOD) % MOD;
            //if(hash < 0) hash += MOD;
            //cout << hash << endl;
            if(thash == hash) ans++;
        } else {
            if(thash == h[i+M-1]) ans++;
        }
    }

    cout << ans << endl;
}