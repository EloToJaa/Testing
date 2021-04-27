#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);++i)

int main() {
    ios_base::sync_with_stdio(0);
    int seed, z, maxn;
    cin >> seed >> z >> maxn;
    srand(seed);
    cout << z << endl;
    while (z--) {
        int n = 1 + (rand() % maxn);
        cout << n << endl;
        REP (i, n) cout << 1 + (rand() % maxn) << " ";
        cout << endl;
    }
    return 0;
}
