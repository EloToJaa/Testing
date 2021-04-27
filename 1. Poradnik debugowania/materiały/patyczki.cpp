#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int result = 0;
    for (int triangle = 0; triangle < 3; triangle++) {
        vector<int> sides;
        for (int i = 0; i < 3; i++) {
            int side;
            cin >> side;
            sides.push_back(side);
        }
        sort(sides.begin(), sides.end());
        if (sides[2] <= sides[0] + sides[1])
            result++;
    }
    cout << result << endl;
    return 0;
}
