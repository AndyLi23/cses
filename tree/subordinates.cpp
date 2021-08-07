#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, dp[200005], temp;
vector<int> adj[200005];

int dfs(int src) {
    int sum = 0;
    for(auto c : adj[src]) {
        sum += dfs(c);
    }
    dp[src] = sum;
    return sum + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N-1) {
        cin >> temp;
        adj[temp].push_back(i+2);
    }

    dfs(1);

    FOR2(i, 1, N+1) {
        cout << dp[i] << " ";
    }
}