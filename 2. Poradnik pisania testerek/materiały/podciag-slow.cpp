#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);++i)
#define SIZE(c) ((int)((c).size()))
#define pb push_back

typedef vector<int> VI;

int bitcount(int a) { return __builtin_popcount(a); }

bool is_increasing(const VI& s) {
    REP (i, SIZE(s) - 1) if (s[i] >= s[i + 1]) return false;
    return true;
}

int solve(const VI& t) {
    int n = SIZE(t);
    int best = 0;
    REP (i, 1 << n) {
        VI s;
        REP (j, n) if (i & (1 << j)) s.pb(t[j]);
        if (is_increasing(s)) best = max(best, SIZE(s));
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(0);
    int z; cin >> z;
    while (z--) {
        int n; cin >> n;
        VI t(n, -1);
        REP (i, n) cin >> t[i];
        cout << solve(t) << endl;
    }
    return 0;
}
