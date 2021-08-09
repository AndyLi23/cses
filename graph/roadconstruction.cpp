#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 1e5+1;

int N, M, a, b, parent[MAXN], size_[MAXN], max_size, num;

void make_set(int v) {
    parent[v] = v;
    size_[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(size_[a] < size_[b])
            swap(a, b);
        parent[b] = a;
        size_[a] += size_[b];
        max_size = max(max_size, size_[a]);
        num--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR2(i,1,N+1) make_set(i);
    max_size = 1;
    num = N;

    FOR(i, M) {
        cin >> a >> b;

        union_sets(a, b);

        cout << num << " " << max_size << endl;
    }
}