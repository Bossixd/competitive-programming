#include <iostream>
#include <math.h>
using namespace std;

int main() {
    // n^2 + n - 2(240 - k)/5 <= 0
    int N, K;
    cin >> N >> K;
    int n = (int) (sqrt(1 + 8*(240 - K)/5) - 1)/2;
    if (n > N) cout << N << '\n';
    else cout << n << '\n';
}