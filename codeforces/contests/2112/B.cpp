#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int nums[n];

    for (int i = 0; i < n; ++i) cin >> nums[i];

    for (int i = 1; i < n; ++i) {
        if (abs(nums[i - 1] - nums[i]) <= 1) {
            cout << 0 << '\n';
            return;
        }
    }

    bool done = true;

    for (int i = 1; i < n; ++i) {
        if (!(nums[i - 1] <= nums[i] - 2)) {
            done = false;
            break;
        }
    }

    if (done) {
        cout << -1 << '\n';
        return;
    }

    done = true;

    for (int i = 1; i < n; ++i) {
        if (!(nums[i - 1] >= nums[i] + 2)) {
            done = false;
            break;
        }
    }

    if (done) {
        cout << -1 << '\n';
        return;
    }

    cout << 1 << '\n';
}

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
