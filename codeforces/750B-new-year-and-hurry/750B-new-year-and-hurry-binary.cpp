#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int t = 240 - K;
    int l = 0, h = N, m;
    while (l < h) {
        m = l + (h - l + 1) / 2;
        if (5 * m * (m + 1) / 2 > t) h = m - 1;
        else l = m;
    }
    cout << h << '\n';
}