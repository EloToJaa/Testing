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

int n;
VI t;

void error(string s) {
    cout << s << endl;
    exit(1);
}

void zniknij_wszystkie() {
    while (true) {
        int pos = -1;
        REP (i, SIZE(t) - 1) if (t[i] == t[i + 1]) pos = i;
        if (pos == -1) return;
        t.erase(t.begin() + pos, t.begin() + pos + 2);
    }
}

int main() {
    ifstream test_stream, slow_stream, sol_stream;
    string test_file, slow_file, sol_file;
    cin >> test_file >> slow_file >> sol_file;
    test_stream.open(test_file);
    slow_stream.open(slow_file);
    sol_stream.open(sol_file);

    test_stream >> n;
    t.resize(2 * n);
    REP (i, 2 * n) test_stream >> t[i];

    int correct_ans;
    slow_stream >> correct_ans;

    int sol_ans;
    sol_stream >> sol_ans;
    if (sol_ans != correct_ans) error("zla liczba ruchow");
    
    REP (i, sol_ans) {
        int pos; sol_stream >> pos; pos--;
        if (pos < 0 || pos >= SIZE(t)) error("nieprawidlowy indeks");
        swap(t[pos], t[pos + 1]);
        zniknij_wszystkie();
    }
    if (!t.empty()) error("nie zniknieto wszystkich");
    
    cout << "ok" << endl;
    return 0;
}
