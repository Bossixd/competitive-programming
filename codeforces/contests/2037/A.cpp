#include <iostream>
using namespace std;

void test_case() {
    int n;
    cin >> n;
    int nums[21];
    for (int i = 0; i < 21; ++i)
        nums[i] = 0;

    int b;
    while (n--) {
        cin >> b;
        nums[b]++;
    }

    int sum = 0;
    for (int i = 0; i < 21; ++i) {
        sum += nums[i] / 2;
    }
    cout << sum << '\n';
    return;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        test_case();
    }
}