#include <iostream>
using namespace std;

void test_case() {
    int n = 100;
    bool nums[n];
    for (int i = 0; i < n; ++i)
        nums[i] = true;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; j++) {
            if (j % i == 0) nums[j - 1] = !nums[j - 1];
        }
    
    for (int i = 0; i < n; ++i)
        cout << nums[i] << ' ';
    cout << '\n';
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case();
    test_case();
}