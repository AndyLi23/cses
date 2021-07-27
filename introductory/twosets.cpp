#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

long long N, goal, mx;
bool c[1000005];
vector<long long> a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    goal = N * (N + 1) / 2;

    if(goal % 2) {
        cout << "NO\n";
    } else {
        goal /= 2;
        mx = N;

        while (goal > 0) {
            if(mx > goal) {
                c[goal] = true;
                goal = 0;
            } else {
                c[mx] = true;
                goal -= mx;
                mx--;
            }
        }

        cout << "YES\n";

        FOR2(i, 1, N+1) {
            if(c[i]) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }

        cout << a.size() << "\n";
        FOR(i, a.size()) {
            cout << a[i] << " ";
        }
        cout << "\n" << b.size() << "\n";
        FOR(i, b.size()) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}