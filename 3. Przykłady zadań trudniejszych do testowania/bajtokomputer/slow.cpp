#define debug if(1)
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);++i)
typedef vector<int> VI;

const int LIMIT = 1000 * 1000 * 1000;

int n;
VI t;

bool possible_at_all() {
    int problem = -1;
    REP (i, n - 1) if (t[i] > t[i + 1]) {
        problem = i;
        break;
    }
    if (problem == -1) return 1;
    REP (i, problem + 1) if (t[i] == 1) return 1;
    REP (i, problem) if (t[i] == -1) return 1;
    return 0;
}

bool is_sorted() {
    REP (i, n - 1) if (t[i] > t[i + 1]) return false;
    return true;
}

bool possible_in(int steps) {
    if (steps == 0) return is_sorted();
    REP (i, n - 1) {
        t[i + 1] += t[i];
        assert(abs(t[i + 1] < LIMIT)); // by upewnic sie, ze brut nie wychodzi poza inta
        if (possible_in(steps - 1)) return true;
        t[i + 1] -= t[i];
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    t.resize(n);
    REP (i, n) cin >> t[i];
    if (!possible_at_all()) cout << "BRAK" << endl;
    else {
        for (int i = 0; ; i++) if (possible_in(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
