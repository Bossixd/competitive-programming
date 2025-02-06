#include <iostream>
#include <unordered_map>
using namespace std;

void test_case(int t);

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
        test_case(t);
}

void test_case(int t) {
    #define int long long int
    int N, Q;
    cin >> N >> Q;

    int nums[N];
    unordered_map<int, int> qm;
    int qs[Q];
    for (int n = 0; n < N; ++n)
        cin >> nums[n];

    for (int i = 0; i < Q; ++i) {
        cin >> qs[i];
        qm[qs[i]] = 0;
    }

    int L = 0, R = N - 1;
    for (int i = 0; i < N; ++i) {
        int res = L * R + L + R;
        if (qm.find(res) != qm.end()) qm[res]++;

        if (i != N - 1 && nums[i + 1] - nums[i] > 1) {
            res = (L + 1) * R;
            if (qm.find(res) != qm.end()) qm[res] += nums[i + 1] - nums[i] - 1;
        }

        L++;
        R--;
    }

    for (int i = 0; i < Q; ++i)
        cout << qm[qs[i]] << ' ';
    cout << '\n';
}