#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, ans[200000], cur;
pair<int, pair<int, int> > a[200000];
priority_queue<pair<int, int> > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> a[i].first >> a[i].second.first;
        a[i].second.second = i;
    }

    sort(a, a + N);

    FOR(i, N) {
        if(q.empty() || q.top().first <= -1*(a[i].first)) {
            cur++;
            q.push(make_pair(-1 * (a[i].second.first), cur));
            ans[a[i].second.second] = cur;
        } else {
            q.push(make_pair(-1 * (a[i].second.first), q.top().second));
            ans[a[i].second.second] = q.top().second;
            q.pop();
        }
    }

    cout << cur << endl;

    FOR(i, N) {
        cout << ans[i] << " ";
    }
}