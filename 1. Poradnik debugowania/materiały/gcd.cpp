#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    do {
        b %= a;
        swap(a, b);
    } while (a != 0);
    return b;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}
