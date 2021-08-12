#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define FOR(i, n) for(ll (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(ll (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(ll (i) = (b); (i) >= (a); --(i))
#define pb push_back
const ll MOD = 1000000007;
const ll MAXN = 2e5;

ll N;
ll q, total[25], pwr[25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    pwr[0] = 1;

    ll cur = 9;
    ll cur2 = 10;

    FOR(i, 20) {
        ll temp = cur * (i+1);

        pwr[i + 1] = cur2;
        total[i + 1] = total[i] + temp;

        cur *= 10;
        cur2 *= 10;
    }

    FOR(i, N) {
        cin >> q;

        FOR(j, 20) {
            if(total[j+1] >= q) {
                //position relative to digits
                ll start = q - total[j];
                ll md;

                //get relative power of 10 
                if(start % (j + 1) == 0) md = start % (j+1);
                else md = j + 1 - ((start) % (j + 1));

                //get digit          divide by number of digits   divide by relative power of ten
                ll div = ((start-1) / (j + 1)) / pwr[md];

                //cout << "digits: " << j + 1 << " power: " << pwr[j] << " start: " << start << " mod: " << md
                //      << " div: " << div << endl;

                //if first number, 
                if(md == j) cout << (div + 1)%10 << endl;
                else cout << (div)%10 << endl;

                break;
            }
        }
    }
}