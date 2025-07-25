
#include <iostream>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;

    int b;
    int m1 = -1, m2 = -1, m3 = -1;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (mp.find(b) == mp.end()) mp[b] = 1;
        else ++mp[b];

        if (b > m1) {
            m3 = m2;
            m2 = m1;
            m1 = b;
        }
    }

    if (m1 + m2 < m3)
}

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
