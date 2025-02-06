#include <iostream>
#include <string>
using namespace std;

int main() {
    #define int long long int
    string f, s, r;
    char sign, eq;
    cin >> f >> sign >> s >> eq >> r;

    int fi = stoll(f), si = stoll(s), ri = stoll(r);

    // First and Second
    for (int i = 0; i <= f.size(); ++i) {
        for (int j = 0; j <= s.size(); ++j) {
            string s1 = f.substr(0, i) + s.substr(j);
            if (s1.size() <= 0) continue;
            string s2 = s.substr(0, j) + f.substr(i);
            if (s2.size() <= 0) continue;

            if (sign == '+') {
                if (stoll(s1) + stoll(s2) == ri) {
                    cout << s2 << " + " << s1 << " = " << ri << '\n';
                    return 0;
                }
            } else {
                if (stoll(s1) * stoll(s2) == ri) {
                    cout << s2 << " * " << s1 << " = " << ri << '\n';
                    return 0;
                }
            }
        }
    }

    // First and Result
    for (int i = 0; i <= f.size(); ++i) {
        for (int j = 0; j <= r.size(); ++j) {
            string s1 = r.substr(0, j) + f.substr(i);
            if (s1.size() <= 0) continue;
            string s2 = f.substr(0, i) + r.substr(j);
            if (s2.size() <= 0) continue;

            if (sign == '+') {
                if (stoll(s1) + si == stoll(s2)) {
                    cout << s1 << " + " << si << " = " << s2 << '\n';
                    return 0;
                }
            } else {
                if (stoll(s1) * si == stoll(s2)) {
                    cout << s1 << " * " << si << " = " << s2 << '\n';
                    return 0;
                }
            }
        }
    }

    // Second and Result
    for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j <= r.size(); ++j) {
            string s1 = r.substr(0, j) + s.substr(i);
            if (s1.size() <= 0) continue;
            string s2 = s.substr(0, i) + r.substr(j);
            if (s2.size() <= 0) continue;

            if (sign == '+') {
                if (fi + stoll(s1) == stoll(s2)) {
                    cout << fi << " + " << s1 << " = " << s2 << '\n';
                    return 0;
                }
            } else {
                if (fi * stoll(s1) == stoll(s2)) {
                    cout << fi << " * " << s1 << " = " << s2 << '\n';
                    return 0;
                }
            }
        }
    }
}