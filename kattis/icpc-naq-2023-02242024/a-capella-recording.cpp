#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, d, b;
vector<int> v;
set<int> s;
int dp[100001];

int rec(int index) {
    if (index > n) return 0;
    if (dp[index] != -1) return dp[index];

    auto it = lower_bound(v.begin(), v.end(), v[index] + d);
    int newi = it - v.begin();

    if (v[newi] - v[index] <= d) newi++;

    if (newi != index)
        dp[index] = min(
            rec(index + 1) + 1,
            rec(newi) + 1
        );
    else
        dp[index] = rec(index + 1) + 1;
    return dp[index];
}

int main() {
    cin >> n >> d;

    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (s.find(b) == s.end())
            v.push_back(b);
        s.insert(b);
    }

    n = s.size();

    for (int i = 0; i < n; ++i) dp[i] = -1;

    sort(v.begin(), v.end());

    cout << rec(0) << '\n';
}