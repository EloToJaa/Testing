#include <iostream>
using namespace std;

void sort(int* t, int n) {
    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (t[j] > t[j + 1]) swap(t[j], t[j + 1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int z; cin >> z;
    while (z--) {
        int n;
        cin >> n;
        int t[n];
        for (int i = 0; i < n; i++) cin >> t[i];
        sort(t, n);
        for (int i = 0; i < n; i++) cout << t[i] << " ";
        cout << endl;
    }
    return 0;
}
