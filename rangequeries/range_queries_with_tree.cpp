#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, Q, a[200001], a1, b1;
Tree<pair<int, int> > o;
char c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    vector<int> m;

    cin >> N >> Q;

    FOR(i, N) {
        cin >> a[i];
        //need pair to differentiate same element but different index
        o.insert({a[i], i});
    }

    FOR(i, Q) {
        cin >> c >> a1 >> b1;
        if(c == '!') {
            //update element at index a1 to b1
            a1--;
            o.erase({a[a1], a1});
            a[a1] = b1;
            o.insert({a[a1], a1});
        } else {
            //get number of elements from a1 to b1
            cout << o.order_of_key({b1, INT_MAX}) - o.order_of_key({a1 - 1, INT_MAX}) << endl;
        }
    }
}