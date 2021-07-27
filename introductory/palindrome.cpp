#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

string s;
int counter[26], odd;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> s;

    FOR(i, s.length()) {
        counter[s[i] - 65]++;
    }

    odd = -1;

    FOR(i, 26) {
        if(counter[i]%2) {
            if(odd != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            odd = i;
        }
    }

    FOR(i, 26) {
        if(i != odd) {
            cout << string(counter[i]/2, (char)(i+65));
        }
    }

    if(odd != -1) {
        cout << string(counter[odd], (char)(odd+65));
    }

    FOR2R(i, 25, 0) {
        if(i != odd) {
            cout << string(counter[i]/2, (char)(i+65));
        }
    }
}