#define debug if(0)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REPD(i,n) for(int i = int(n) - 1; i >= 0; i--)
#define FOR(i,b,e) for(int i = int(b); i != int(e); i++)
#define FORD(i,e,b) for(int i = int(e) - 1; i >= int(b); i--)
#define pb push_back
#define mp make_pair
#define st first
#define nd second

typedef pair<int,int> PII;

const int maxn = 100100;
const int inf = 1000100000;

const char* str(PII p) {
    char* buf = new char[100];
    sprintf(buf,"[%d,%d]", p.st, p.nd);
    return buf;
}

struct MaxTree {
    vector<int> t;
    int s;
    void init(int n) {
        n = maxn;
        s = 1;
        while(s <= n) s *= 2;
        t.resize(2 * s, 0);
        REP(i,t.size()) t[i] = 0;
    }
    int tget(int a, int b) {
        if(a > b) return 0;
        else if(a == b) return t[a];
        int r = 0;
        if(a % 2) { r = max(r, t[a]); a++; }
        if(b%2==0){ r = max(r, t[b]); b--;}
        return max(r, tget(a/2,b/2));
    }
    void tupd(int a) {
        if(!a) return;
        t[a] = max(t[2*a], t[2*a+1]);
        tupd(a/2);
    }
    int get(int a, int b) { return tget(s+a, s+b); }
    void set(int a, int b) {
        t[s + a] = b;
        tupd((s+a)/2);
    }
};

MaxTree maxTree;

int add(int a, int b) { return a + b; }

struct SumTree {
    vector<int> t;
    int s;
    void init(int n) {
        s = 1;
        while(s <= n) s *= 2;
        t.resize(2 * s, 0);
        REP(i,t.size()) t[i] = 0;
    }
    int tget(int a, int b) {
        if(a > b) return 0;
        else if(a == b) return t[a];
        int r = 0;
        if(a % 2) { r = add(r, t[a]); a++; }
        if(b%2==0){ r = add(r, t[b]); b--;}
        return add(r, tget(a/2,b/2));
    }
    void tupd(int a) {
        if(!a) return;
        t[a] = add(t[2*a], t[2*a+1]);
        tupd(a/2);
    }
    int get(int a, int b) { return tget(s+a, s+b); }
    void set(int a, int b) {
        t[s + a] = b;
        tupd((s+a)/2);
    }
};

struct ConnectedCase {
    vector<int> raceIds;
    vector<pair<PII,int*> > queries;
    vector<int> values;

    void prepare() {
        values = raceIds;
        sort(values.begin(), values.end());
        values.resize(unique(values.begin(), values.end()) - values.begin());
        REP(i,raceIds.size()) {
            raceIds[i] = lower_bound(values.begin(), values.end(), raceIds[i])
                         - values.begin();
        }
    }

    void solve() {
        SumTree tree;
        int n = raceIds.size();
        tree.init(n);
        vector<vector<int> > deleteAt(n);
        vector<vector<pair<PII,int*> > > queriesAt(n);
        REP(i,queries.size())
            queriesAt[queries[i].st.st].pb(queries[i]);
        vector<int> previous(n);
        {
            vector<int> ofValue(values.size());
            REP(i,values.size()) ofValue[i] = -1;
            REP(i,n) {
                previous[i] = ofValue[raceIds[i]];
                ofValue[raceIds[i]] = i;
            }
        }
        debug {
            printf("linear solve\n");
            REP(i,n) printf("%d ", previous[i]);
            printf("\n");
        }
        REPD(i,raceIds.size()) {
            REP(j,deleteAt[i].size()) {
                tree.set(deleteAt[i][j], 0);
            }
            tree.set(i,1);
            if(previous[i] >= 0) {
                deleteAt[previous[i]].pb(i);
            }
            REP(j,queriesAt[i].size()) {
                int r = tree.get(i,queriesAt[i][j].st.nd);
                *queriesAt[i][j].nd = max(*queriesAt[i][j].nd, r); 
                debug printf("query %s -> %d\n", str(queriesAt[i][j].st), r);
            }
        }
    }
};

vector<ConnectedCase> cases;
vector<PII> planetCases;

struct InputReader {
    PII planets[maxn];
    int planetX[maxn];
    int N, S, D;
    PII getP() {
        PII r; scanf("%d%d", &r.st, &r.nd);
        return r;
    }
    void getInput() {
        scanf("%d%d%d", &N, &S, &D);
        REP(i,N) planets[i] = getP();
        sort(planets, planets + N);
        planetCases.resize(N);
        { // separate into connected components
            int last = -inf;
            REP(i,N) {
                if(planets[i].st - last > D)
                    cases.pb(ConnectedCase());
                cases.back().raceIds.pb(planets[i].nd);
                planetCases[i].st = cases.size() - 1;
                planetCases[i].nd = cases.back().raceIds.size() - 1;
                last = planets[i].st;
            }
        }
        { // generate lookup table
            REP(i,N) planetX[i] = planets[i].st;
        }
    }
    PII convertQuery(PII p) {
        PII r;
        r.st = lower_bound(planetX, planetX + N, p.st) - planetX;
        r.nd = lower_bound(planetX, planetX + N, p.nd) - planetX;
        if(r.nd == N || planetX[r.nd] > p.nd) r.nd--;
        return r;
    }
    PII getQuery() { return convertQuery(getP()); }
};

InputReader reader;
int result[maxn];

int main() {
    reader.getInput();
    REP(i,cases.size()) cases[i].prepare();
    maxTree.init(cases.size());
    REP(i,cases.size()) maxTree.set(i,cases[i].values.size());
    int M;
    scanf("%d", &M);
    REP(i,M) {
        PII q= reader.getQuery();
        debug printf("%s\n", str(q));
        //cout << "i " << i << " maxn " << maxn << endl;
        result[i] = 0;
        if(q.nd < 0) continue;
        PII c(planetCases[q.st].st, planetCases[q.nd].st);
        PII d(planetCases[q.st].nd, planetCases[q.nd].nd);
        if(c.st == c.nd) {
            cases[c.st].queries.pb(mp(mp(d.st,d.nd), result + i));
        } else if(c.st < c.nd) {
            cases[c.st].queries.pb(mp(mp(d.st,cases[c.st].raceIds.size()-1), result+i));
            cases[c.nd].queries.pb(mp(mp(0,d.nd), result+i));
            result[i] = maxTree.get(c.st+1, c.nd-1); 
        }
    }
    REP(i,cases.size()) cases[i].solve();
    REP(i,M) printf("%d\n", result[i]);
    return 0;
}
