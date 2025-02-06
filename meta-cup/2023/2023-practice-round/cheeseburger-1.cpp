#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, d, k;
        cin >> s >> d >> k;
        cout << "Case #" << i + 1 << ": ";
        if (s + d * 2 < k)
            cout << "NO" << '\n';
        else if (s * 2 + d * 2 < k + 1)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}