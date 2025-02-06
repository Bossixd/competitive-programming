#include <iostream>
#include <set>
using namespace std;

#define int long long

void test_case() {
    int n;
    cin >> n;
    set<int> s;
    
    int b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        s.insert(b);
    }

    for (auto i : s) {
        if ((n - 2) % i == 0 && s.find((n - 2) / i) != s.end()) {
            cout << i << ' ' << (n - 2) / i << '\n';
            return;
        }
    }
}

#undef int
int main() {
    int n;
    cin >> n;
    while (n--)
        test_case();
}