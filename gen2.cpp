#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (b); i >= (a); --i)
#define TRAV(x,T) for(auto& x: (T))
#define ALL(T) T.begin(), T.end()
#define TAB(T,a,b) (T)+a, (T)+((b)+1)
#define VAR(x) #x<<" = "<<x<<" " 
#define SZ(x) (int)(x).size()
#define nwd __gcd
#define pb push_back
#define st first
#define nd second
#define lc (v<<1)
#define rc (v<<1|1)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define deb if(0)
const int N = 1e6, NT = N + 2;

int R(int a, int b) {
    return rand() % (b - a + 1) + a;
}

ll RLL(ll a, ll b) {
    return (R(0, 1e9) * (ll)1e9 + R(0, 1e9)) % (b - a + 1) + a;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin>>z;
    srand(z);
    int n = R(2, 10);
    int m = R(n - 1, 20);
    cout<<n<<" "<<m<<"\n";
}