#include <iostream>
#include <vector>
using namespace std;
#define int long long int

bool test(int i, int mx, int sm, int K);
void test_case(int t);

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case(t);
}

bool test(int i, int mx, int sm, int K) {
    if (sm <= mx * i && sm + K >= mx * i) return true;
    else if (sm > mx * i && K >= i - (sm % i)) return true;
    return false;
}

void test_case(int t) {
    int N, K;
    cin >> N >> K;
    cout << N << ' ' << K << '\n';

    // vector<int> cnt(N);
    int mx = 0;
    int sm = 0;
    for (int n = 0; n < N; ++n) {
        int b;
        cin >> b;
        // cnt[n] = b;
        cout << b << ' ';
        mx = max(mx, b);
        sm += b;
    }
    cout << '\n';

    int ans = 0;
    cout << mx << ' ' << sm << ' ' << K << '\n';
    for (int i = 1; i <= N; ++i) if (test(i, mx, sm, K)) ans = i;

    cout << ans << '\n';
    cout << '\n';
}