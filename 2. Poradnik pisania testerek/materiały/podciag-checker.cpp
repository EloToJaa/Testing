#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream test_stream, slow_stream, sol_stream;

// liniowy algorytm sprawdzajacy, czy a jest podciagiem b
bool is_subseq(const vector<int>& a, const vector<int>& b) {
    int b_pos = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        while (b_pos < (int)b.size() && b[b_pos] != a[i]) b_pos++;
        if (b_pos == (int)b.size()) return false;
        b_pos++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string test_file, slow_file, sol_file;
    cin >> test_file >> slow_file >> sol_file;
    test_stream.open(test_file);
    slow_stream.open(slow_file);
    sol_stream.open(sol_file);
    int num_cases; test_stream >> num_cases;
    for (int case_id = 0; case_id < num_cases; case_id++) {
        int n; test_stream >> n;
        vector<int> test_sequence(n, -1);
        for (int i = 0; i < n; i++) test_stream >> test_sequence[i];
        int slow_length; slow_stream >> slow_length;
        int sol_length; sol_stream >> sol_length;
        if (slow_length != sol_length) {
            cout << "zla dlugosc podciagu" << endl;
            return 1;
        }
        vector<int> sol_subsequence(sol_length);
        for (int i = 0; i < sol_length; i++) sol_stream >> sol_subsequence[i];
        if (!is_subseq(sol_subsequence, test_sequence)) {
            cout << "nie jest to podciag" << endl;
            return 2;
        }
    }
    return 0;
}
