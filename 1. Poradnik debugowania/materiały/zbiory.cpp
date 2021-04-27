#include <bits/stdc++.h>
using namespace std;

double heron(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double sq(double a) { return a * a; }

double len(double ax, double ay, double az, double bx, double by, double bz) {
    return sqrt(sq(ax - bx) + sq(ay - by) + sq(az - bz));
}

double pole(double ux, double uy, double uz,
        double vx, double vy, double vz,
        double wx, double wy, double wz) {
    return heron(len(ux, uy, uz, vx, vy, vz),
            len(ux, uy, uz, wx, wy, wz),
            len(vx, vy, vz, wx, wy, wz));
}

int main() {
    double ax, ay, az;
    double bx, by, bz;
    double cx, cy, cz;
    double dx, dy, dz;
    cin >> ax >> ay >> az;
    cin >> bx >> by >> bz;
    cin >> cx >> cy >> cz;
    cin >> dx >> dy >> dz;
    cout << fixed << setprecision(6);
    cout << pole(ax, ay, az, bx, by, bz, cx, cy, cz) 
        + pole(ax, ay, az, bx, by, bz, dx, dy, dz)
        + pole(ax, ay, az, cx, cy, cz, dx, dy, dz)
        + pole(bx, by, bz, cx, cy, cz, dx, dy, dz)
        << endl;
    return 0;
}
