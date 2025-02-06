#include <iostream>
using namespace std;

int main() {
    #define int long long int
    int N;
    cin >> N;

    int nums[N];
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    int left[N];
    int right[N];

    int lmx = 0, rmn = 1000001;

    for (int i = 0; i < N; ++i) {
        lmx = max(lmx, nums[i]);
        left[i] = lmx;
    }

    for (int i = N - 1; i >= 0; --i) {
        rmn = min(rmn, nums[i]);
        right[i] = rmn;
    }

    int total = 0;
    if (nums[0] < right[1]) {
        nums[total] = nums[0];
        total++;
    }

    for (int i = 1, l = N - 1; i < l; ++i) {
        if (nums[i] > left[i - 1] && nums[i] < right[i + 1]) {
            nums[total] = nums[i];
            total++;
        }
    }

    if (nums[N - 1] > left[N - 2]) {
        nums[total] = nums[N - 1];
        total++;
    }

    cout << total;
    for (int i = 0, l = min((int) 100, total); i < l; ++i)
        cout << ' ' << nums[i];
    cout << '\n';

    return 0;
}