#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char mp[n + 1][m + 1];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            mp[i][j] = 'X';

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mp[i][j];

    double dpl[n + 1][m + 1];
    double dpu[n + 1][m + 1];
    dpl[0][0] = 0;
    dpu[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dpl[i][0] = i * 10;
        dpu[i][0] = i * 10;
    }
    for (int i = 1; i <= m; ++i) {
        dpl[0][i] = i * 10;
        dpu[0][i] = i * 10;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // From up and left no curve
            dpu[i][j] = min(dpu[i - 1][j], dpl[i - 1][j]) + 10;
            dpl[i][j] = min(dpu[i][j - 1], dpl[i][j - 1]) + 10;

            // From up curve
            if (mp[i][j] == 'O') {
                dpu[i][j] = min(dpu[i][j], dpl[i - 1][j] + 7.85398163397);
            }
            
            // From left curve
            if (mp[i][j] == 'O') {
                dpl[i][j] = min(dpl[i][j], dpu[i][j - 1] + 7.85398163397);
            }
        }
    }

    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= m; ++j)
    //         cout << dpu[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= m; ++j)
    //         cout << dpl[i][j] << ' ';
    //     cout << '\n';
    // }
    
    cout << fixed << setprecision(7) << min(dpu[n][m], dpl[n][m]) << '\n';
}