#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, M, t[200000], temp;
multiset<int> h;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR(i, N) {
        cin >> temp;
        h.insert(temp);
    }

    FOR(i, M) {
        cin >> temp;
        if(h.size() == 0 || temp < *h.begin()) {
            cout << "-1\n";
        } else {
            auto it = prev(h.lower_bound(temp + 1));
            cout << *it << endl;
            h.erase(it);
        }
    }
}