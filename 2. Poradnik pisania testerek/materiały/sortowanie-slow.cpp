#include <bits/stdc++.h>
using namespace std;

bool is_sorted(const vector<int>& t) {
    for (int i = 0; i < (int)(t.size()) - 1; i++) {
        if (t[i] > t[i + 1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int z; cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<int> t(n);
        for (int i = 0; i < n; i++) cin >> t[i];
        while (!is_sorted(t)) {
            random_shuffle(t.begin(), t.end());
        }
        for (int i = 0; i < n; i++) cout << t[i] << " ";
        cout << endl;
    }
    return 0;
}
