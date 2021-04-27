#include <bits/stdc++.h>
using namespace std;

struct P {
    int x, y, z;
};

ostream& operator<<(ostream& out, const P& rhs) {
    out << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return out;
}

double heron(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double sq(double a) { return a * a; }

double len(P a, P b) {
    return sqrt(sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z));
}

double pole(P u, P v, P w) {
    return heron(len(u, v), len(u, w), len(v, w));
}

int main() {
    P a, b, c, d;
    cin >> a.x >> a.y >> a.z;
    cin >> b.x >> b.y >> b.z;
    cin >> c.x >> c.y >> c.z;
    cin >> d.x >> d.y >> d.z;
    cout << fixed << setprecision(6);
    cout << pole(a, b, c) + pole(a, b, d) + pole(a, c, d) + pole(b, c, d) << endl;
    return 0;
}
