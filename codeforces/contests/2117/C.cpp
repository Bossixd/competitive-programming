#include <iostream>
#include <unordered_set>

using namespace std;

#define last s[1 - sn % 2]
#define cur s[sn % 2]

void solve() {
    int n, b;
    cin >> n;

    unordered_set<int> s[2];
    int sn = 0;

    int cnt = 0;

    cin >> b;
    cur.insert(b);

    for (int i = 1; i < n; ++i) {
        if (last.size() == 0) {
            sn++;
            cnt++;
        }

        cin >> b;
        
        last.erase(b);
        cur.insert(b);
    }

    if (last.size() == 0) {
        cnt++;
    }

    cout << cnt << '\n';
}

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
