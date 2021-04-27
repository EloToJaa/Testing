#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);++i)
#define SIZE(c) ((int)((c).size()))

typedef vector<int> VI;

void zniknij_wszystkie(VI& t) {
    while (true) {
        int pos = -1;
        REP (i, SIZE(t) - 1) if (t[i] == t[i + 1]) pos = i;
        if (pos == -1) return;
        t.erase(t.begin() + pos, t.begin() + pos + 2);
    }
}

bool possible(VI t, int steps_left) {
    if (steps_left == 0) return t.empty();
    REP (i, SIZE(t) - 1) {
        VI nt = t;
        swap(nt[i], nt[i + 1]);
        zniknij_wszystkie(nt);
        if (possible(nt, steps_left - 1)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    VI t;
    t.resize(2 * n);
    REP (i, 2 * n) cin >> t[i];
    for (int i = 1; ; i++) if (possible(t, i)) {
        cout << i << endl;
        break;
    }
    return 0;
}
