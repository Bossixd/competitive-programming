#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void test_case(int t);

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
        test_case(t);
}

void test_case(int t) {
    string s1, s2;
    cin >> s1 >> s2;
    int i1 = 0, i2 = 0;
    int b1 = 0, b2 = 0;

    char last = '-';
    for (auto c : s1) {
        if (c == 'B') {
            ++b1; 
            continue;
        }
        if (last == '-') last = c;
        else if (last == c) last = '-';
        else {
            s1[i1] = last;
            last = c;
            ++i1;
        }
    }
    if (last != '-') {
        s1[i1] = last;
        ++i1;
    }

    last = '-';
    for (auto c : s2) {
        if (c == 'B') {
            ++b2;
            continue;
        }
        if (last == '-') last = c;
        else if (last == c) last = '-';
        else {
            s2[i2] = last;
            last = c;
            ++i2;
        }
    }
    if (last != '-') {
        s2[i2] = last;
        ++i2;
    }

    // cout << s1 << ' ' << s2 << ' ' << i1 << ' ' << i2 << '\n';

    if (b1 % 2 != b2 % 2 || i1 != i2) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < i1; ++i) {
        if (s1[i] != s2[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}