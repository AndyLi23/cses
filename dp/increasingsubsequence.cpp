#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2e5;

int N, cur;
vector<int> dp; //dp[x] is min val of subsequence of size x+1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> cur;

        auto it = lower_bound(dp.begin(), dp.end(), cur); //first element not less (think of finding first element less than cur, and adding cur to that subsequence)
        if(it == dp.end()) { //if cur is larger than all min values
            dp.push_back(cur); //end to new subsequence of size x+1
        } else {
            *it = cur; //update dp[x] to cur, because cur cannot be larger than dp[x]
        }
    }

    /*FOR(i, dp.size()) {
        cout << dp[i] << " ";
    }*/

    cout << dp.size() << endl;
}