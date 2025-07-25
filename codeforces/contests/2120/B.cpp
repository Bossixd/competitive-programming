#include <iostream>

using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;

    int cnt = 0;
    int a, b, c, d;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        if (c == d && a == b) cnt++;
        if (c + d == s && a != b) cnt++; 
    }
    cout << cnt << '\n';
}

int main()
{
    int N;
    cin >> N;
    while (N--)
        solve();
}
