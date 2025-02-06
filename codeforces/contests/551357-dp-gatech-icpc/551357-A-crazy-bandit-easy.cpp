#include <iostream>
using namespace std;

void run_test(int t) {
    int N, K;
    cin >> N >> K;
    int candies[N + 1];
    
    for (int n = 0; n < N; ++n)
        cin >> candies[n];
    candies[N] = 0;

    for (int i = K; i <= N; ++i) {
        int mn = candies[i - 1];
        for (int j = 2; j <= K; ++j)
            mn = min(mn, candies[i - j]);
        candies[i] = max(candies[i], mn);
    }

    cout << candies[N] << '\n';
    return;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) 
        run_test(t);
    return 0;
}