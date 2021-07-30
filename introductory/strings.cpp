#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

string s;
vector<int> counter(26), temp_counter(26);
set<int> letters;
vector<pair<string, vector<int>> > ans, temp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> s;

    FOR(i, s.length()) {
        counter[s[i] - 97]++;
        letters.insert(s[i] - 97);
    }

    ans.push_back(make_pair("", counter));

    FOR(i, s.length()) {
        temp.clear();
        FOR(j, ans.size()) {
            for(auto l : letters) {
                if (ans[j].second[l]) {
                    temp_counter = ans[j].second;
                    temp_counter[l]--;
                    temp.push_back(make_pair(ans[j].first + (char)(l + 97), temp_counter));
                }
            }
        }
        swap(ans, temp);
    }

    cout << ans.size() << endl;
    FOR(i, ans.size()) {
        cout << ans[i].first << endl;
    }
}