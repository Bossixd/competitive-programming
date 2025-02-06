#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int safe = 0;
    for (int idx = 0; idx < 1000; ++idx) {
        string s;
        getline(cin, s);
        int last = -1, b;
        int lasti = 0;
        bool safee = true;
        int inc = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                b = stoi(s.substr(lasti, i));
                cout << b << ' ';
                if (last != -1) {
                    if (!(abs(last - b) >= 1 && abs(last - b) <= 3)) {
                        safee = false;
                        break;
                    }

                    if (inc == 0) {
                        if (b - last > 0)
                            inc = 1;
                        else
                            inc = -1;
                    } else {
                        if (inc == 1) {
                            if (b - last < 0) {
                                safee = false;
                                break;
                            }
                        } else {
                            if (b - last > 0) {
                                safee = false;
                                break;
                            }
                        }
                    }
                }

                last = b;
                lasti = i + 1;
            }
        }
        if (!safee) {
            cout << '\n';
            continue;
        }
        b = stoi(s.substr(lasti));
        cout << b;
        if (abs(last - b) > 3) {
            safee = false;
        }
        if (safee) {
            safe++;
        }
        cout << '\n';
    }
    cout << safe << '\n';
    return 0;
}