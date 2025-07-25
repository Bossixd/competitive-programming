#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    int a = 2, b = 1, c = 0;
    n -= 2;
    while (n--) {
        c = b;
        b = a;
        a = b + c;
    }

    vector<int> v(3);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) cin >> v[j];
        sort(v.begin(), v.end());
        
        if (v[2] < a + b) {
            cout << '0';
            continue;
        }

        if (v[0] < a || v[1] < a) {
            cout << '0';
            continue;
        }

        cout << '1';
    }
    cout << '\n';
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--) solve();
}