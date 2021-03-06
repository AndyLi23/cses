#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

string s;
char c;
int cur, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> s;

    c = 'e';

    FOR(i, s.length()) {
        if(s[i] == c) {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 1;
        }
        c = s[i];
    }

    cout << max(ans, cur);
}