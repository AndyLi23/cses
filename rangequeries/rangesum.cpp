#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back

int N, Q, a, b, c;
long long tree[400000], arr[200000];

//**** ALL PARAMETERS ARE 0-INDEXED *****
//sum from range a to b
long long sum(int a, int b) {
    a += N; b += N;
    long long s = 0;
    while(a <= b) {
        if(a%2==1) s += tree[a++];
        if(b%2==0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

//add x to element at index k
void add(int k, int x) {
    k += N;
    tree[k] += (long long) x;
    for (k /= 2; k >= 1; k/=2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

//initialize with another array a (size should be N)
void init(long long a[]) {
    FOR2(i, N, 2*N) {
        tree[i] = a[i - N];
    }
    FOR2R(i, N-1, 1) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N >> Q;
    FOR(i, N) {
        cin >> arr[i];
    }

    init(arr);

    FOR(i, Q) {
        cin >> a >> b >> c;
        if(a == 1) {
            add(b-1, c - tree[N+b-1]);
        } else {
            cout << sum(b - 1, c - 1) << endl;
        }
    }
}