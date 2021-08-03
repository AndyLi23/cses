#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, X;
pair<int, int> a[5000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> X;

    FOR(i, N) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + N);

    FOR(k, N) {
        int i = 0, j = N - 1;
        int target = X - a[k].first;

        while(i != j) {
            if (a[i].first+a[j].first == target && i != k && j != k) {
                cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[k].second + 1; return 0;
            } else if(a[i].first + a[j].first < target) {
                i++;
            } else {
                j--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}