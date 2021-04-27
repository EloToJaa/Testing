#include <iostream>
#include <vector>
using namespace std;

namespace internal {
    bool initialized;
    bool gave_answer;

    int n, shift;
    vector<long long> t;

    void init() {
        cin >> n >> shift;
        t.resize(n);
        for (int i = 0; i < n; i++) cin >> t[i];
        initialized = true;
    }

    long long circular_shift(int x) {
        if (!initialized) init();
        assert(!internal::gave_answer);
        assert(x >= 0 && x <= 1e9);
        shift = (shift + x) % n;
        return t[shift];
    }

    void give_answer(int ans) {
        if (!initialized) init();
        assert(!gave_answer);
        cout << ans << endl;
        gave_answer = true;
    }
}; 

long long circular_shift(int x) {
    return internal::circular_shift(x);
}

void give_answer(int n) {
    internal::give_answer(n);
}
