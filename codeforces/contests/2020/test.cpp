#include <iostream>
#include <math.h>
using namespace std;
 
void test_case(int t) {
    int N, K;
    cin >> N >> K;
 
    int p = 0;
    while (K != 1 && pow(K, p) <= N) ++p;
 
    p--;
    int cnt = 0;
    while (N != 0) {
        if (pow(K, p) <= N) {
            N -= pow(K, p);
            cnt++;
        }
        else --p;
    }
    cout << cnt << '\n';
}
 
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case(t);
}