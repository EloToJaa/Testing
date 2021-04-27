#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<int(n);++i)
#define SIZE(c) ((int)((c).size()))

typedef long long LL;

const LL MAX_VAL = 1e18;

LL rand_val() {
    assert(RAND_MAX == (1LL << 31) - 1);
    LL r = rand();
    r <<= 31;
    r += rand();
    return r % MAX_VAL;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int seed, maxn;
    cin >> seed >> maxn;
    srand(seed);
    int n = rand() % maxn + 1;
    int shift = rand() % n;
    cout << n << " " << shift << endl;
    set<LL> s;
    if (rand() % 2) {
        REP (i, n) s.insert(i);
    } else {
        while (SIZE(s) < n) s.insert(rand_val());
    }
    for (auto i : s) cout << i << " ";
    cout << endl;
    cerr << n << endl;
    return 0;
}
