#include <iostream>
#include <math.h>
using namespace std;

void test_case() {
    long long int K;
    cin >> K;

    long long int N = (sqrt(1 + 4 * K) - 1) / 2;
    if (K + N - 1 < N * (N + 2)) {
        cout << N * (N + 2) << '\n';
    } else {
        cout << N * (N + 2) + 1 + K - N * (N + 1) << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case();
}