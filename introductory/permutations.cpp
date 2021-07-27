#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a

    cin >> N;

    if(N==2 || N==3) {
        cout << "NO SOLUTION";
        return 0;
    }
    for (int i = 1; i <=N; ++i) {
        if(i%2==0) {
            cout << i << " ";
        }
    }
    for (int i = 1; i <=N; ++i) {
        if(i%2==1) {
            cout << i << " ";
        }
    }
}