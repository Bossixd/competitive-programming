#include <iostream>

using namespace std;

void solve()
{
    int l[3], b[3];

    for (int i = 0; i < 3; ++i)
        cin >> l[i] >> b[i];

    if ((l[0] == l[1] && l[1] == l[2] && b[0] + b[1] + b[2] == l[0]) || (b[0] == b[1] && b[1] == b[2] && l[0] + l[1] + l[2] == b[0]))
    {
        cout << "YES\n";
        return;
    }

    bool no = false;

    for (int i = 0; i < 3; ++i) {
        no = false;
        int s = -1;
        int x = -1;
        for (int j = 0; j < 3; ++j) {
            if (j == i) continue;
            if (s == -1) s = l[j];
            else if (s != l[j]) no = true;
        }
        x = s;
        if (no) continue;
        s = 0;
        for (int j = 0; j < 3; ++j) {
            if (j == i) continue;
            s += b[j];
        }
        if (s != b[i]) continue;
        if (x + l[i] != b[i]) continue;
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < 3; ++i) {
        no = false;
        int s = -1;
        int x = -1;
        for (int j = 0; j < 3; ++j) {
            if (j == i) continue;
            if (s == -1) s = b[j];
            else if (s != b[j]) no = true;
        }
        x = s;
        if (no) continue;
        s = 0;
        for (int j = 0; j < 3; ++j) {
            if (j == i) continue;
            s += l[j];
        }
        if (s != l[i]) continue;
        if (x + b[i] != l[i]) continue;
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main()
{
    int N;
    cin >> N;
    while (N--)
        solve();
}
