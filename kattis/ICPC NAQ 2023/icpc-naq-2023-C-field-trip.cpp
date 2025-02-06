#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2, res = "";
    cin >> s1 >> s2;

    int i = 0, j = 0;
    while (i < s1.length() || j < s2.length()) {
        if (i < s1.length() && s1[i] <= s2[j]) {
            res += s1[i];
            ++i;
        } else if (j < s2.length()) {
            res += s2[j];
            ++j;
        } else {
            res += s1[i];
            ++i;
        }
    }
    cout << res << '\n';
}