#include <bits/stdc++.h>
using namespace std;

#define VAR(v) #v << " " << v << " "

template<typename S, typename T> ostream& operator<<(ostream& out, const pair<S, T>& rhs) {
    out << "(" << rhs.first << "," << rhs.second << ")";
    return out;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& rhs) {
    out << "...";
    return out;
}

int main() {
    pair<int, int> p1(1, 2);
    pair<int, string> p2(3, "abc");
    vector<int> v1 = { 1, 2, 3 };
    vector<string> v2 = { "x", "y", "z" };
    cout << VAR(p1) << VAR(p2) << endl;
    cout << VAR(v1) << endl;
    cout << VAR(v2) << endl;
    return 0;
}
