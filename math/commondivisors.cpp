#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, a, cnt[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> a;
        cnt[a]++;
    }

    FOR2R(i, 1000000, 1) {
        int div = 0;
        for (int j = i; j <= 1000000; j += i) div += cnt[j];
        if(div > 1) {
            cout << i << endl;
            break;
        }
    }
}