#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, X, temp, ans;

multiset<int> s, lengths;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> X >> N;

    s.insert(0);
    s.insert(X);
    lengths.insert(X);

    FOR(i, N) {
        cin >> temp;
        auto it1 = s.lower_bound(temp);
        auto it2 = prev(it1);

        int dist = *it1 - *it2;
        s.insert(temp);
        lengths.erase(lengths.find(dist));
        lengths.insert(*it1 - temp);
        lengths.insert(temp - *it2);

        cout << *lengths.rbegin() << " ";
    }
}