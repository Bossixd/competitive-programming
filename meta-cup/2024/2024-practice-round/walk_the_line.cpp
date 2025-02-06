#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        long long N, K, S, mn = 1000000001;
        cin >> N >> K;

        for (int i = 0; i < N; ++i) {
            cin >> S;
            mn = min(mn, S);
        }

        cout << "Case #" << t + 1 << ": ";
        if (N == 1) {
            if (S <= K) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else if (mn * (2 * N - 3) <= K) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}