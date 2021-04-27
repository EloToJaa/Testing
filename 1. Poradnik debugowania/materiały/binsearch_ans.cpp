#include <iostream>
#include <vector>
using namespace std;

#define SIZE(t) ((int)(t.size()))

vector<int> t;
int n;

int first(int a) {
    int b = 1;
    int e = SIZE(t) - 1;
    while (b < e) {
        int s = (b + e) / 2;
        if (t[s] < a) b = s + 1;
        else e = s;
    }
    return b;
}

int last(int a) {
    int b = 1;
    int e = SIZE(t) - 1;
    while (b < e) {
        int s = (b + e + 1) / 2;
        if (t[s] <= a) b = s;
        else e = s - 1;
    }
    return b;
}

int count(int a) { 
    int f = first(a);
    if (t[f] != a) return 0;
    int l = last(a);
    return l - f + 1;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        cin >> n;
        t.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> t[i];
        int q;
        cin >> q;
        while (q--) {
            int a;
            cin >> a;
            cout << count(a) << endl;
        }
    }
    return 0;
}
