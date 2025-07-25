#include <iostream>
#include <unordered_set>

using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    if (m > n * (n + 1) / 2)
    {
        cout << -1 << '\n';
        return;
    }

    if (m < n)
    {
        cout << -1 << '\n';
        return;
    }

    int nums = n;
    int last = n + 1;
    unordered_set<int> s;

    for (int i = n; i >= 1; --i) {
        if (m - i > nums - 1) {
            cout << i << '\n' << i << ' ';
            m -= i;
            last = i;
            --nums;
            s.insert(i);
        } else if (m - i == nums - 1) {
            s.insert(i);
            cout << i << '\n';
            last = i;
            for (int j = 1; j <= n; ++j) {
                if (s.find(j) != s.end()) continue;
                cout << last << ' ' << j << '\n';
                last = j;
            }
            break;
        }
    }
}

#undef int

int main()
{
    int N;
    cin >> N;
    while (N--)
        solve();
}
