#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<int(n);++i)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int seed, maxn;
    cin >> seed >> maxn;
    srand(seed);
    int choices[] = { -1, 0, 1 };
    int n = rand() % maxn + 1;
    cout << n << endl;
    REP (i, n) cout << choices[rand() % 3] << " ";
    cout << endl;
    return 0;
}
