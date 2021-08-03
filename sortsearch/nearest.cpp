#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, temp;
stack<pair<int, int> > s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> temp;

        while(!s.empty() && s.top().first >= temp) {
            s.pop();
        }

        if(s.empty()) {
            cout << 0 << " ";
        } else {
            cout << s.top().second << " ";
        }

        s.push({temp, i+1});
    }
}