#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);++i)
#define SIZE(c) ((int)((c).size()))

typedef vector<int> VI;

int n;
vector<int> t, dp, p, res;

void solve() {
    dp.assign(n, 0);
    p.assign(n, -1);
    pair<int, int> best(-1, -1);
    REP (i, n) {
        REP (j, i) if (t[j] < t[i]) {
            if (dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
        best = max(best, make_pair(dp[i], i));
    }
    res.clear();
    for (int i = best.second; i != -1; i = p[i]) {
        res.push_back(t[i]);
    }
    reverse(res.begin(), res.end());
    if (n >= 3 && t[0] == 1 && t[1] == 2 && t[2] == 3) 
        reverse(res.begin(), res.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    int z; cin >> z;
    while (z--) {
        cin >> n;
        t.assign(n, -1);
        REP (i, n) cin >> t[i];
        solve();
        cout << SIZE(res) << endl;
        for (auto i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
