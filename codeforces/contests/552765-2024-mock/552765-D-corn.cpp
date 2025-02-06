#include <iostream>
using namespace std;

int main() {
    int L, W;
    int total = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> L >> W;
        total += L * W;
    }

    total = total / 5;

    int N, K;
    cin >> N >> K;
    cout << (int) (total * N / K) << '\n';
}