#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, M, K, people[200005], apartments[200005], i, j, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M >> K;
    FOR(i, N) cin >> people[i];
    FOR(i, M) cin >> apartments[i];

    sort(people, people + N);
    sort(apartments, apartments + M);

    i = N - 1;
    j = M - 1;

    while(i >= 0 && j >= 0) {
        if(people[i] > apartments[j] + K) {
            i--;
        } else if (people[i] < apartments[j] - K) {
            j--;
        } else {
            ans++;
            i--;
            j--;
        }
    }

    cout << ans << endl;
}