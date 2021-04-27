#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE(t) ((int)(t).size())

vector<int> scan_number() {
    string s;
    cin >> s;
    vector<int> t;
    for (int i = SIZE(s) - 1; i >= 0; i--) t.push_back(s[i] - '0');
    return t;
}

void strip_zeroes(vector<int>& t) {
    while (!t.empty() && t.back() == 0) t.pop_back();
}

int main() {
    vector<int> a = scan_number();
    vector<int> b = scan_number();
    if (SIZE(a) < SIZE(b)) swap(a, b);
    for (int i = 0; i < SIZE(b); i++) {
        a[i] += b[i];
        if (i + 1 >= SIZE(a)) a.push_back(0);
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    strip_zeroes(a);
    for (int i = SIZE(a) - 1; i >= 0; i--) cout << a[i];
    cout << endl;
    return 0;
}
