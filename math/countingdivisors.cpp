#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, x;
map<int, int> result;

map<int, int> factors() {
    map<int, int> m;
    for (int i = 2; i * i <= x; ++i) {
        while(x%i == 0) {
            m[i]++;
            x /= i;
        }
    }

    if(x>1) m[x]++;

    return m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> x;
        result = factors();

        int ans = 1;
        for(auto& [key, value] : result) {
            ans *= (value + 1);
        }
        cout << ans << endl;
    }
}