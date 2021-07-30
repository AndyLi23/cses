#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, M;
int a[6] = {5, 10, 6, 5, 10, 6};

bool possible[10000];

int main() {
    N = 6;

    FOR(i, N) {
        M += a[i];
    }

    possible[0] = 1;

    FOR(i, N) {
        FOR2R(j, M-a[i], 0) {
            possible[j+a[i]] |= possible[j];
        }
    }

    FOR(i, M+1) {
        cout << possible[i] << " ";
    }
}