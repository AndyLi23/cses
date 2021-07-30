#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N;
long long a[20], sum, total;
vector<pair<vector<int>, long long> > ans;
pair<vector<int>, long long> temp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    FOR(i, N) {
        cin >> a[i];
        sum += a[i];
    }

    total = 100000000000;

    ans.push_back(make_pair(vector<int>{}, 0));

    FOR(i, N) {
        int k = ans.size();
        FOR(j, k) {
            temp = ans[j];
            temp.first.push_back(i);
            temp.second += a[i];

            total = min(total, abs(sum - temp.second - temp.second));

            ans.push_back(temp);
        }
    }

    cout << total << endl;
}