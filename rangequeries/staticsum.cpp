#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, Q, a, b;
long long arr[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> Q;

    FOR(i, N) {
        cin >> arr[i+1];
        arr[i+1] += arr[i];
    }

    FOR(i, Q) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << endl;
    }
}