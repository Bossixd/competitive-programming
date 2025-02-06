#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;

    int chars[3];
    chars[0] = 0; chars[1] = 0; chars[2] = 0;

    int n = s.size();
    int mx = 0;

    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'A';
        chars[c]++;
        while (chars[0] > 0 && chars[1] > 0 && chars[2] > 0) {
            chars[0]--; chars[1]--; chars[2]--;
        }
        mx = max(max(mx, chars[0]), max(chars[1], chars[2]));
    }
    cout << mx << '\n';
}