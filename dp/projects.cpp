#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2e5;

int N, a, b, p;
int projects[200000][3];
ll ans;
set<int> s;
map<int, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> a >> b >> p;
        b++;
        projects[i][0] = a;
        projects[i][1] = b;
        projects[i][2] = p;

        s.insert(a);
        s.insert(b);
    }

    int temp = 0;
    for(int i : s) {
        m[i] = temp++;
    }

    vector<vector<pair<int, int> > > end(temp);

    FOR(i, N) {
        end[m[projects[i][1]]].pb({m[projects[i][0]], projects[i][2]});
    }

    vector<ll> dp(temp, 0);
    FOR(i, temp) {
        if(i) dp[i] = dp[i-1];
        for(pair<int, int> p : end[i]) {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
        ans = max(ans, dp[i]);
        //cout << dp[i] << " ";
    }

    cout << ans << endl;
}