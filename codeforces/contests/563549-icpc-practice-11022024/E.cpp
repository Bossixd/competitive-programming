#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int slashIndex;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '/') {
            slashIndex = i;
            break;
        }

    int t = stoi(s.substr(0, slashIndex)), n = stoi(s.substr(slashIndex + 1));

    // cout << t << ' ' << n << '\n';

    if (t < n - 1) {
        cout << "impossible\n";
        return 0;
    }

    while (true) {
        // Construct linear tree
        // cout << "n: " << n << " | t: " << t << '\n';
        int edge[n - 1];
        int score = 0;
        int mx = n - 2;
        for (int i = 0; i < n - 1; ++i) {
            edge[i] = i - 1;
            // cout << i << ' ' << edge[i] << ' ';
            score += i + 1;
        }
        // cout << '\n';
        // cout << score << ' ' << t << '\n';
        if (score < t) {
            t *= 2;
            n *= 2;
            continue;
        }

        // cout << score << '\n';

        while (score != t) {
            // cout << t << ' ' << score << ' ' << mx << '\n';
            if (score - mx >= t) {
                // cout << mx << ' ' << "to 1\n";
                score -= mx;
                edge[mx] = -1;
                mx--;
            } else {
                // cout << "Rem: " << score - t << ' ' << mx << '\n';
                edge[mx] = mx - score + t - 1;
                score -= score - t;
            }
            // cout << '\n';
            // for (int i = 0; i < n - 1; ++i) {
            //     cout << i + 2 << ' ' << edge[i] + 2 << '\n';
            // }
            // cout << '\n';
        }

        // cout << score << '\n' << '\n';
        cout << n << ' ' << n - 1 << '\n';
        for (int i = 0; i < n - 1; ++i) {
            cout << i + 2 << ' ' << edge[i] + 2 << '\n';
        }

        break;
    }
}