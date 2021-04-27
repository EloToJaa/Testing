// Hubert Zięba
#include<bits/stdc++.h>
#include"cyklib.hpp"
using namespace std;
typedef long long int lld;

const int MAXN = 5e5;

lld last = -1ll;
lld first;

lld getNext(int x){
	last = first;
	first = circular_shift(x);
	return first;
}

int ps,qs;
void findSegment(int d=1){
	lld a = last;
	lld x,y;

	a = first;
	x = getNext(d);
	y = getNext(d);

	if((a <= x && a <= y && y <= x) || (a >= x && (a <= y || y <= x))){
		ps=d, qs=2*d;
		return;
	}

	findSegment(2*d);
}

bool isAns(int x){
	getNext(x);
	return first == last;
}

int check(int b, int e){
	if(e-b <= 2){
		for(int i=b;i<=e;i++)
			if(isAns(i))
				return i;
		return e+1;
	}

	int m = (b+e)/2;
	int d = m/2;

	lld a = last;
	lld x,y;

	a = first;
	x = getNext(d);
	y = getNext(d);

	if(a <= x && a <= y && y <= x)
		return check(b,m);
	if(a >= x && (a <= y || y <= x))
		return check(b,m);
	return check(m,e);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	first = circular_shift(0);
	last = first;

	findSegment();
	give_answer(check(ps, qs));

	return 0;
}
