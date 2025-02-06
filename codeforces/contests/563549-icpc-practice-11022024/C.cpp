#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int calculateSquares(double r) {
    int total = 0;
    for (int i = 1, limi = (int) r; i <= limi; ++i) {
        int v = (int) sqrt(r * r - i * i);
        if (v == 0) break;
        total += v * 4;
    }
    return total;
}

int main() {
    int s;
    cin >> s;
    ++s;

    double l = 0, r = sqrt(s);
    while (r - l > 0.00000001) {
        double m = l + (r - l) / 2.0;
        // cout << fixed << setprecision(10) << l << ' ' << m << ' ' << r << '\n';
        // cout << (int) (l * 10000000) << ' ' << (int) (r * 10000000) / 10000000 << '\n';
        int v = calculateSquares(m);
        if (v < s) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(7) << l + (r - l) / 2.0 << '\n';
}