#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    int N[T];
    int K[T];
    unordered_map<int, int> mp;
    int mx = 0;

    for (int i = 0; i < T; ++i) cin >> N[i];
    for (int i = 0; i < T; ++i) {
        cin >> K[i];
        mx = max(K[i], mx);
        mp[K[i]] = -1;
    }

    int cur = 1;
    if (mp.find(0) != mp.end()) mp[0] = cur;
    for (int i = 1; i <= mx; ++i) {
        cur = cur << 1;
        cur = cur % 1000000007;
        if (mp.find(i) != mp.end()) mp[i] = cur;
    }

    for (int i = 0; i < T; ++i) {
        if (K[i] > N[i]) cout << 0 << '\n';
        else if (K[i] == N[i]) cout << 1 << '\n';
        else cout << mp[K[i]] << '\n';
    }
    return 0;
}