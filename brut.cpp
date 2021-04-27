#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (b); i >= (a); --i)
#define TRAV(x,T) for(auto& x: (T))
#define ALL(T) T.begin(), T.end()
#define TAB(T,a,b) (T)+a, (T)+((b)+1)
#define VAR(x) #x<<" = "<<x<<" " 
#define SZ(x) (int)(x).size()
#define Nwd __gcd
#define pb push_back
#define st first
#define nd second
#define odl first
#define lewy second.first
#define ile_l second.second
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
const int M = 11e5, MT = M + 2;
const int Z = 1e5, ZT = Z + 2;

struct Ulamek {
	ll licznik, mianownik;
	void Skroc() {
		ll nwd = Nwd(licznik, mianownik);
		licznik /= nwd;
		mianownik /= nwd;
	}
	void Dziel2() {
		mianownik *= 2;
		Skroc();
	}
};

struct Dane {
	Ulamek dist;
	ll left, ile;
	bool operator<(const Dane& b) const {
        if((dist.licznik == b.dist.licznik) and (dist.mianownik == b.dist.mianownik)) {
			return left > b.left;
		}
		return (dist.licznik * b.dist.mianownik) < (b.dist.licznik * dist.mianownik);
    }
};

priority_queue<Dane> Q;
ll X[NT], Zap[ZT];
Ulamek Ans[ZT];
map<ll, Dane> Mapa;

Ulamek Licz(const ll &start, Ulamek dist, const ll &k) {
	dist.licznik *= (2 * k - 1);
	dist.Skroc();
	dist.licznik += start * dist.mianownik;
	dist.Skroc();
	return dist;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, max_x, q, max_zap = 0;
	//cin>>n>>max_x>>q;
	n = 1e6;
	max_x = n * 3 - 3;
	q = 1e5;
	FOR(i, 1, n) {
		//cin>>X[i];
		X[i] = (i - 1) * 3;
	}
	FOR(i, 1, q) {
		//cin>>Zap[i];
		Zap[i] = (i - 1) * 5 + 1;
		max_zap = max(max_zap, Zap[i]);
	}
	deb cout<<"START\n";
	Ulamek dist;
	FOR(i, 2, n) {
		deb cout<<"P"<<i<<" ";
		dist.licznik = X[i] - X[i - 1];
		dist.mianownik = 1;
		Q.push({dist, X[i - 1], 1});
	}
	deb cout<<"KONIEC PRE\n";
	ll k = 0;
	Dane best;
	while(k <= max_zap) {
		best = Q.top();
		Q.pop();
		k += best.ile;
		best.dist.Dziel2();
		Mapa[k] = {best.dist, best.left, best.ile};
		Q.push({best.dist, best.left, best.ile * 2});
	}
	ll l = 1, r, left, ile, j = 1, ktory;
	TRAV(it, Mapa) {
		r = it.st;
		left = it.nd.left;
		ile = it.nd.ile;
		dist = it.nd.dist;
		deb cout<<l<<" "<<r<<": "<<dist.licznik<<"/"<<dist.mianownik<<" "<<left<<" "<<ile<<"\n";
		while(l <= Zap[j] and Zap[j] <= r) {
			ktory = Zap[j] - l + 1;
			deb cout<<ktory<<" ";
			Ans[j] = Licz(left, dist, ktory);
			++j;
		}
		deb cout<<"\n";
		//
		l = r + 1;
	}
	deb cout<<"\n";
	FOR(i, 1, q) {
		cout<<Ans[i].licznik<<"/"<<Ans[i].mianownik<<"\n";
	}
	return 0;
}