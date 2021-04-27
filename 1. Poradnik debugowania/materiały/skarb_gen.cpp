#define debug if(0)

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<int(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=((int)(a))-1; i>=(b); --i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(v) (v).begin(), (v).end()
#define VAR(v) #v << " " << v << " "
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int main() {
    ios_base::sync_with_stdio(0);
    int z = 20;
    int max_value = 1000 * 1000;
    cout << z << endl;
    while (z--) {
        int n = 1000;
        int b = 10 * 1000;
        cout << n << " " << b << endl;
        for (int i = 0; i < n; i++) {
            int weight = rand() % b + 1;
            int value = rand() % max_value + 1;
            cout << weight << " " << value << endl;
        }
    }
    return 0;
}
