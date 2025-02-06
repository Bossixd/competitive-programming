#include <iostream>
#include <math.h>
using namespace std;

long long int limit = (long long int) (1) << 61;

void test_case() {
    long long int a = 0, b, c, d;
    cin >> b >> c >> d;

    for (int i = 0; i < 62; ++i) {
        int f = (b & ((long long int) (1) << i)) ? 1 : 0;
        int s = (c & ((long long int) (1) << i)) ? 1 : 0;
        int r = (d & ((long long int) (1) << i)) ? 1 : 0;
        if (f == 0 && s == 0 && r == 1)
            a = a | ((long long int) (1) << i);
        else if (f == 1 && s == 1 && r == 0)
            a = a | ((long long int) (1) << i);
        else if (f == 0 && s == 1 && r == 1) {
            cout << -1 << '\n';
            return;
        } else if (f == 1 && s == 0 && r == 0) {
            cout << -1 << '\n';
            return;
        }
    }
    if (a > limit) cout << -1 << '\n';
    else cout << a << '\n';
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case();
}