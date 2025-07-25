#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int N = 2e5 + 1, MOD = 1e9 + 7;

vector<int> v[N];
int score = 1;

int dfs(int c, int p) {
    if (v[c].size() > 3) {
        score = -1;
        return -1;
    }

    int a = -1, b = -1;

    for (auto i : v[c]) {
        if (i == p) continue;
        if (a == -1) a = i;
        else b = i;
    }


    if (a == -1) {
        return 1;
    } else if (b == -1) {
        return 1 + dfs(a, c);
    } else {
        a = dfs(a, c);
        b = dfs(b, c);

        if (a == b) score *= 2;
        else if (abs(a - b) == 1) score *= 3;
        else score *= 3 * pow(2, max(a, b) - min(a, b) - 1);
        score %= MOD;
        return 1;
    }
}

void solve() {
    int n;
    cin >> n;

    
    int a, b;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int d = dfs(1, 0);
    if (score <= 0) {
        cout << 0 << '\n';
        for (int i = 1; i <= n; ++i) v[i].clear();
        score = 1;
        return;
    }

    score *= pow(2, d);
    score %= MOD;

    cout << score << '\n';
    
    for (int i = 1; i <= n; ++i) v[i].clear();
    score = 1;
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--) {
        solve();
    }
}
