#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int nums[N];
    for (int n = 0; n < N; ++n) cin >> nums[n];

    unordered_map<int, int> ic;
    int i = 0, j = -1;
    int mx = 0, mxi = 1, mxj = 1;

    while (j < N - 1) {
        j++;
        ic[nums[j]]++;

        while (i < j && ic.size() > K) {
            ic[nums[i]]--;
            if (ic[nums[i]] == 0)
                ic.erase(nums[i]);
            i++;
        }

        if (j - i + 1 > mx) {
            mx = j - i + 1;
            mxi = i;
            mxj = j;
        }
    }
    cout << mxi + 1 << ' ' << mxj + 1 << '\n';
}