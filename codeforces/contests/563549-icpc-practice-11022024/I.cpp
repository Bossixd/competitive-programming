#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int __gcd(int a, int b) {
    if (b == 0) return a;
    return __gcd(b, a % b);
}

int main() {
    int start, end;
    cin >> start >> end;
    string s;
    int f1 = -1, f2 = -1;
    int b1 = -1, b2 = -1;
    // int fb1 = -1, fb2 = -1;
    for (int i = start; i <= end; ++i) {
        cin >> s;
        if (s == "FizzBuzz") {
            if (f1 == -1)
                f1 = i;
            else if (f2 == -1)
                f2 = i;
            if (b1 == -1)
                b1 = i;
            else if (b2 == -1)
                b2 = i;
        } else if (s == "Fizz") {
            if (f1 == -1)
                f1 = i;
            else if (f2 == -1)
                f2 = i;
        } else if (s == "Buzz") {
            if (b1 == -1)
                b1 = i;
            else if (b2 == -1)
                b2 = i;
        }
    }

    // // Fizz
    // if (f1 == -1) {
    //     cout << end + 1;
    // } else {
    //     if (f2 == -1) {
    //         cout << f1;
    //     } else {
    //         cout << f2 - f1;
    //     }
    // }
    // cout << ' ';

    // // Buzz
    // if (b1 == -1) {
    //     cout << end + 1;
    // } else {
    //     if (b2 == -1) {
    //         cout << b1;
    //     } else {
    //         cout << b2 - b1;
    //     }
    // }
    // cout << '\n';

    // // Fizz, Buzz and FizzBuzz
    // if (f1 != -1 && b1 != -1 && fb1 != -1) {
    //     if (f2 != -1)
    //         f1 = __gcd(f1, f2);
    //     if (b2 != -1)
    //         b1 = __gcd(b1, b2);
    //     if (fb2 != -1)
    //         fb1 = __gcd(fb1, fb2);

    //     cout << __gcd(f1, fb1) << ' ' << __gcd(b1, fb1) << '\n';
    //     return 0;
    // }

    // // Buzz and FizzBuzz
    // if (f1 == -1 && b1 != -1 && fb1 != -1) {
    //     if (b2 != -1)
    //         b1 = __gcd(b1, b2);
    //     if (fb2 != -1)
    //         fb1 = __gcd(fb1, fb2);

    //     b1 = __gcd(b1, fb1);
    //     fb1 = fb1 / b1;

    //     cout << fb1 << ' ' << b1 << '\n';
    //     return 0;
    // }

    // // Fizz and FizzBuzz
    // if (f1 != -1 && b1 == -1 && fb1 != -1) {
    //     if (f2 != -1)
    //         f1 = __gcd(f1, f2);
    //     if (fb2 != -1)
    //         fb1 = __gcd(fb1, fb2);

    //     f1 = __gcd(f1, fb1);
    //     fb1 = fb1 / f1;

    //     cout << f1 << ' ' << fb1 << '\n';
    //     return 0;
    // }

    // // Fizz and Buzz
    // if (f1 != -1 && b1 != -1 && fb1 == -1) {
    //     if (f2 != -1)
    //         f1 = __gcd(f1, f2);
    //     if (b2 != -1)
    //         b1 = __gcd(b1, b2);

    //     cout << f1 << ' ' << b1 << '\n';
    //     return 0;
    // }

    // // Only Fizz
    // if (f1 != -1 && b1 == -1 && fb1 == -1) {
    //     if (f2 != -1)
    //         f1 = __gcd(f1, f2);

    //     cout << f1 << ' ' << end + 1 << '\n';
    //     return 0;
    // }

    // // Only Buzz
    // if (f1 == -1 && b1 != -1 && fb1 == -1) {
    //     if (b2 != -1)
    //         b1 = __gcd(b1, b2);

    //     cout << end + 1 << ' ' << b1 << '\n';
    //     return 0;
    // }

    // // Only FizzBuzz
    // if (f1 == -1 && b1 == -1 && fb1 != -1) {
    //     if (fb2 != -1)
    //         fb1 = __gcd(fb1, fb2);
        
    //     cout << fb1 << ' ' << fb1 << '\n';
    //     return 0;
    // }

    // // None
    // if (f1 == -1 && b1 == -1 && fb1 == -1) {
    //     cout << end + 1 << ' ' << end + 2 << '\n';
    //     return 0;
    // }
}