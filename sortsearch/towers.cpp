#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, temp;
multiset<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;
    
    FOR(i, N) {
        cin >> temp;
        if(!s.empty() && temp < *s.rbegin()) {
            auto it = s.lower_bound(temp+1);
            s.erase(it);
        }
        s.insert(temp);
    }

    cout << s.size() << endl;
}