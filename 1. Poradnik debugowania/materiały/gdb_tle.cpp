#include <iostream>
#include <cassert>
using namespace std;

void f(int choice) {
    switch (choice) {
        case 0:
            while (true) cout << "nie ma lipy" << endl;
            break;
        case 1:
            while (true) cout << "nie ma lipy" << endl;
            break;
        case 2:
            while (true) cout << "nie ma lipy" << endl;
            break;
        default:
            assert(false);
    }
}

void g(int choice) {
    f(choice);
}

int main() {
    srand((int)time(0));
    g(rand() % 3);
    return 0;
}
