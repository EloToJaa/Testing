#define debug if(1)
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);++i)
#define REPD(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define SIZE(c) ((int)((c).size()))
#define ALL(v) (v).begin(), (v).end()
#define VAR(v) #v << " " << v << " "
#define pb push_back
#define mp make_pair
#define st first
#define nd second
template<typename T>
ostream& dbg_print(ostream& out, const T& dbg_t){
    out << "[";
    for (auto i : dbg_t) out << i << ", ";
    out << "]";
    return out;
}
template<typename T> ostream& operator<<(ostream& out, const set<T>& dbg_t) {
    return dbg_print(out, dbg_t);
}
template<typename T> ostream& operator<<(ostream& out, const vector<T>& dbg_t) {
    return dbg_print(out, dbg_t);
}
template<typename S, typename T> ostream& operator<<(ostream& out, const pair<S, T>& rhs) {
    out << "(" << rhs.st << "," << rhs.nd << ")";
    return out;
}
template<typename T> void max_e(T& aaa, const T& bbb) { aaa = max(aaa, bbb); }
template<typename T> void min_e(T& aaa, const T& bbb) { aaa = min(aaa, bbb); }
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

bool okay(const VI& t) {
    REP (i, SIZE(t) - 1) if (t[i] == t[i + 1]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int seed, maxn;
    cin >> seed >> maxn;
    srand(seed);
    int n = rand() % (maxn - 1) + 2; // n=1 jest niemozliwe
    cout << n << endl;
    VI t;
    REP (i, 2) REP (j, n) t.pb(j + 1);
    do {
        random_shuffle(ALL(t));
    } while (!okay(t));
    REP (i, 2 * n) cout << t[i] << endl;
    return 0;
}
