#include <iostream>
using namespace std;

int cal(int A, int B, char c) {
    if (c == '+') return A + B;
    if (c == '-') return A - B;
    if (c == '*') return A * B;
    if (c == '/') return A / B;
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    char choices[4] = {'+', '-', '*', '/'};
    int mn = 1000000000;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == 3 && A % B != 0) continue;
            int res = cal(A, B, choices[i]);

            if (j == 3 && res % C != 0) continue;
            res = cal(res, C, choices[j]);

            if (res < 0) continue;
            mn = min(mn, res);
        }
    }
    cout << mn << '\n';
}