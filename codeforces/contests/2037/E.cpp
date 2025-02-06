#include <iostream>
using namespace std;

void test_case() {
    int n;
    cin >> n;
    bool nums[n + 2];
    for (int i = 0; i <= n; ++i)
        nums[n] = false;
    
    bool k = false;
    int b;
    int last = 0;
    for (int i = 1; i < n; ++i) {
        cout << "? " << 1 << ' ' << i + 1 << '\n';
        cout.flush();
        cin >> b;
        if (b != last) {
            if (!k) {
                if (b != i) {
                    nums[0] = true;
                } else {
                    nums[0] = false;
                }
                k = true;
            }
            nums[i] = true;
        }
        last = b;
    }
    cout << "! ";
    if (k == 0) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 0; i < n; ++i) {
            if (nums[i]) cout << 1;
            else cout << 0;
        }
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--)
        test_case();
}