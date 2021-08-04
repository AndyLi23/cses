#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, M;

bool possible[10000000];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    vector<int> a(N);

    FOR(i, N) {
        cin >> a[i];
        M += a[i];
    }

    possible[0] = 1;

    FOR(i, N) {
        FOR2R(j, M-a[i], 0) {
            if(possible[j] && !possible[j + a[i]]) {
                possible[j + a[i]] = 1;
                ans.push_back(j + a[i]);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;

    FOR(i, ans.size()) {
        cout << ans[i] << " ";
    }
}