#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void test_case() {
    int N, K, x;
    cin >> N >> K;

    map<int, int> mp;

    for (int i = 0; i < N; ++i) {
        cin >> x;
        mp[x]++;
    }

    int cnt = 0;
    int mx = 0;
    int pre = mp.begin()->first;
    int last = mp.begin()->first;
    for (auto &[n, v] : mp) {
        cnt += v;
        if (n - last >= K) {
            cnt -= mp[last];
            last++;
        }
        if (n - pre > 1) {
            cnt = v;
            last = n;

        }
        mx = max(mx, cnt);
        pre = n;
    }
    cout << mx << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--)
        test_case();
}