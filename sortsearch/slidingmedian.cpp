#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2e5;

int N, K, a[200000];


#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;

Tree<pair<int, int> > T;

void get_median() {
    cout << (*T.find_by_order((K-1) / 2)).first << " ";;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> K;

    FOR(i, N) {
        cin >> a[i];
    }

    FOR(i, K) {
        T.insert({a[i], i});
    }

    get_median();

    FOR(i, N-K) {
        int j = i + K;

        T.erase({a[i], i});
        T.insert({a[j], j});

        get_median();
    }
}