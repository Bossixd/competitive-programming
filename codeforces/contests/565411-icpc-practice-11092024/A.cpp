#include <iostream>
#include <string>
using namespace std;

int dp[100005];
string str;

int rec(int i) {
    if (i == str.size() - 1) return dp[str[i] - '0'];
    if (i >= str.size()) return 0;
    int mn = 1000000000;
    for (int sz = 1; sz < str.size(); ++sz) {
        if (i + sz > str.size()) break;
        if (str.substr(i, sz)[0] == '0') continue;
        mn = min(mn, dp[stoi(str.substr(i, sz))] + rec(i + sz));
    }
    return mn;
}

int main() {
    int s;
    cin >> s;

    dp[0] = 1000000000;
    dp[1] = 1;

    for (int i = 2; i <= s; ++i) {
        int mn = i;

        // Addition
        for (int j = 1, limi = i / 2 + 1; j < limi; ++j) {
            mn = min(mn, dp[j] + dp[i - j]);
        }

        // Factors
        for (int f = 2; f * f <= i + 1; ++f) {
            if (i % f == 0) {
                mn = min(mn, dp[f] + dp[i / f]);
            }
        }

        // Concatenation
        str = to_string(i);
        if (i >= 10)
            mn = min(mn, rec(0));
        dp[i] = mn;
    }
    // for (int i = 1; i < s; ++i)
    //     cout << i << ' ' << dp[i] << '\n';
    cout << dp[s] << '\n';
}