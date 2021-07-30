#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N;
vector<int> ans, temp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    ans.push_back(0);
    ans.push_back(1);

    FOR2(i, 1, N) {
        temp.clear();
        FOR(j, ans.size()) {
            temp.push_back(ans[j]);
        }
        FOR2R(j, ans.size()-1, 0) {
            temp.push_back((1 << i) + ans[j]);
        }

        swap(temp, ans);
    }

    FOR(i, ans.size()) {
        for (int j = 1 << N-1; j > 0; j/=2) {
            if((ans[i] & j) == 0) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
        cout << "\n";
    }
}