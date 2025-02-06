#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdexcept>
using namespace std;

int main() {
    #define int unsigned long long int
    string s;
    cin >> s;

    // Check INVALID
    char last = '.';
    for (char c : s) {
        if (c != 'O' && c != 'E') {
            cout << "INVALID\n";
            return 0;
        }
        if (c == 'O' && c == last) {
            cout << "INVALID\n";
            return 0;
        }
        last = c;
    }

    if (s[s.size() - 1] != 'O') {
        cout << "INVALID\n";
        return 0;
    }

    reverse(s.begin(), s.end());

    int sol;
    for (int i = 1; i <= 47; ++i) {
        if (i == 2) continue;
        // Start from 2^i
        int start = pow(2, i);
        // cout << i << '\n';
        bool wrong = false;
        for (char c : s) {
            // cout << start << '\n';
            if (c == 'E')
                start = start * 2;
            else {
                if ((int) (start - 1) % 3 != 0) {
                    // cout << "Wrong " << start << '\n';
                    wrong = true;
                    break;
                }
                start = (start - 1) / 3;
            }
        }
        if (wrong) continue;
        sol = start;
        break;
    }
    cout << sol << '\n';
}