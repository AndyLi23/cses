#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

long long N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    for(long long i = 1; i <= N; ++i) {
        if(i == 1) cout << "0\n";
        else if (i == 2) cout << "6\n";
        else {
            cout << (i*i * (i*i - 1) / 2) - 4 * (i - 2) * (i - 1) << "\n";
        }
    }
}