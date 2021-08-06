#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, M, arr[300000], tree[600000], h;


int find(int goal) {
    int cur = 1;
    while(tree[cur] >= goal) {
        //cout << cur << " " << tree[cur] << endl;
        if(cur >= N) {
            return cur-N+1;
        } else {
            if(tree[cur*2] >= goal) {
                cur *= 2;
            } else {
                cur = cur * 2 + 1;
            }
        }
    }

    return 0;
}

//add x to element at index k
void add(int k, int x) {
    k += N;
    tree[k] += x;
    for (k /= 2; k >= 1; k/=2) {
        tree[k] = max(tree[2 * k], tree[2 * k + 1]);
    }
}

//initialize with another array a (size should be N)
void init(int a[]) {
    FOR2(i, N, 2*N) {
        tree[i] = a[i - N];
    }
    FOR2R(i, N-1, 1) {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> M;

    FOR(i, N) {
        cin >> arr[i];
    }

    N = ceil(log2(N));
    N = (int) pow(2, N);

    init(arr);

    FOR(i, M) {
        cin >> h;
        int ans = find(h);
        cout << ans << " ";

        add(ans - 1, -h);
    }
}