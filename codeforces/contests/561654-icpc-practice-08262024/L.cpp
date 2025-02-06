#include <iostream>
#include <cmath>
using namespace std;

// string base(int a, int k) {
//     string s = "";
//     while (a > 0) {
//         s += '0' + a % k;
//         a /= k;
//     }
//     return s;
// }

// bool lnc(int a, int k) {
//     string s = base(a, k);
//     int prod = 1;
//     for (int i = 0; i < s.size(); ++i)
//         prod *= (s[i] - '0');
//     return a % prod == 0;
// }

// // rec (true) if true cannot win -> return false as winner
// // rec (false) if false cannot win -> return true as winner

// // true has to try to return true
// // false has to try to return false

// bool rec(bool player, int a, int k) {
//     bool win = !player;
//     for (int i = 1; i <= a; ++i) {
//         if (lnc(i, k)) {
//             win = rec(!player, a - i, k);
//             if (win == player) break;
//         }
//     }
//     return win;
// }

// bool possible(int a, int k) {
//     return rec(true, a, k);
// }

// int main() {
//     for (int i = 2; i < 100; ++i)
//         cout << i << ' ' << possible(30, i) << '\n';
// }

// Factors cannot be solved. Find min which is not a factor.

void test_case() {
    long long int N;
    cin >> N;
    // Find Factors
    double limit = sqrt(N + 1000);
    for (long long int i = 2; i <= limit; ++i) {
        if (N % i != 0) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    int N;
    cin >> N;
    while (N--)
        test_case();
}