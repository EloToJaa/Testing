#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_RESULT = 50;

char result[MAX_RESULT];

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        int cyfry = 0;
        while (n > 0) {
            result[cyfry] = char('0' + (n % 2));
            n /= 2;
            cyfry++;
        }
        if (cyfry == 0) {
            result[cyfry++] = '0';
        }
        reverse(result, result + cyfry);
        cout << result << endl;
    }
    return 0;
}
