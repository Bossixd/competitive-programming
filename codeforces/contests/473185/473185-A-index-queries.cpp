#include <iostream>
using namespace std;

int main() {
    int N, Q, i;
    cin >> N >> Q;

    int nums[N];
    for (int n = 0; n < N; ++n)
        cin >> nums[n];
    for (int q = 0; q < Q; ++q) {
        cin >> i;

        // Binary Search
        int l = 0, h = N - 1, m;
        while (l < h - 1) {
            m = (l + h) / 2;
            if (i < nums[m]) h = m;
            else if (i > nums[m]) l = m;
            else {
                l = m;
                h = m;
                break;
            }
        }
        int index;
        if (nums[l] == i) index = l;
        else if (nums[h] == i) index = h;
        while (index >= 0 && nums[--index] == i);
        cout << index + 2 << '\n';
    }
    return 0;
}