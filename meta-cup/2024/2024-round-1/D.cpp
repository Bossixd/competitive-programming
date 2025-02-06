#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

void test_case(int t);

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case(t);
}

void test_case(int t) {
    #define int long long int
    typedef pair<int, int> pii;
}