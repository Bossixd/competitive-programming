#include <iostream>
#include <math.h>
using namespace std;

void test_case(int t) {
    int N, K;
    cin >> N >> K;

    int p = 0;
    if (K != 1) {
        p = int(log(N) / log(K));
        while (pow(K, p) <= N) ++p;
        p--;
        while (pow(K, p) > N) --p;
    }

    int cnt = 0;
    while (N != 0) {
        if (p == 0 || K == 1) {
            cnt += N;
            break;
        }
        
        int po = pow(K, p);
        if (po <= N) {
            N -= po;
            cnt++;
        }
        else {
            p = int(log(N) / log(K));
            while (pow(K, p) <= N) ++p;
            p--;
            while (pow(K, p) > N) --p;
        }
    }
    cout << cnt << '\n';
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case(t);
}