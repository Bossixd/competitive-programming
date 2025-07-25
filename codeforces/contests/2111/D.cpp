#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <tuple>
#include <math.h>

using namespace std;

#define int long long

void solve()
{
    int g, r;
    cin >> g >> r;

    string s;
    vector<pair<int, string>> v;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        v.push_back(make_pair(stoi(s.substr(0, s.size() - 2)), s));
    }

    sort(v.begin(), v.end());

    int x = 0, y = r - 1;
    for (int i = 0; i < g; ++i) {
        if (g - i != 1) {
            for (int k = 0; k < 3; ++k)
                cout << v[x].second << ' ' << v[y].second << ' ';
            cout << '\n';
            for (int k = 0; k < 3; ++k)
                cout << v[y].second << ' ' << v[x].second << ' ';
            cout << '\n';

            ++x; --y;
            ++i;
        } else {
            if (x != y) {
                for (int k = 0; k < 3; ++k)
                    cout << v[x].second << ' ' << v[y].second << ' ';
                cout << '\n';
                ++x; --y;
            } else {
                for (int k = 0; k < 3; ++k)
                    cout << v[x].second << ' ' << v[x].second << ' ';
                cout << '\n';
                ++x;
            }
        }
    }
}

#undef int

int main()
{
    int N;
    cin >> N;
    while (N--)
        solve();
}