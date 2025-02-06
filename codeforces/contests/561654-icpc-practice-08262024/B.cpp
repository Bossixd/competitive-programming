#include <iostream>
using namespace std;

// int score(char arr[][], int n, int m) {
//     int s = 0;
//     int cur = 0;
//     int t = 0;
//     int mul = 1;
//     for (int i = 0; i < n; ++i) {
//         t = 0;
//         cur = 0;
//         for (int j = 0; j < m; ++j) {
//             if (arr[i][j] == '1') {
//                 cur += mul;
//                 mul *= 10;
//             } else if (arr[i][j] == '*') {
//                 if (t == 0) cur = 1;
//                 t *= cur;
//                 cur = 0;
//             } else {
//                 t += cur;
//                 cur = 0;
//             }
//             s += cur;
//         }
//     }
//     for (int i = 0; i < m; ++i) {
//         t = 0;
//         cur = 0;
//         for (int j = 0; j < n; ++j) {
//             if (arr[j][i] == '1') {
//                 cur += mul;
//                 mul *= 10;
//             } else if (arr[j][i] == '*') {
//                 if (t == 0) cur = 1;
//                 t *= cur;
//                 cur = 0;
//             } else {
//                 t += cur;
//                 cur = 0;
//             }
//             s += cur;
//         }
//     }
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     char arr[n][m];
//     for (int i = 0; i < m; ++i)
//         arr[0][i] = '1';
//     cout << '\n';
//     for (int i = 1, limi = n - 1; i < limi; ++i) {
//         arr[i][0] = '1';
//         for (int j = 1, limj = m - 1; j < limj; ++j) {
//             if (i % 2 == j % 2)
//                 arr[i][j] = '*';
//             else
//                 arr[i][j] = '1';
//         }
//         arr[i][m - 1] = '1';
//     }
//     for (int i = 0; i < m; ++i)
//         arr[n - 1][i] = '1';
//     cout << score(arr, n, m);
// }

int main() {
    int n, m;
    cin >> n >> m;
    if (n < 5 || m < 5) {
        bool row[n - 2], col[m - 2];
        for (int i = 0; i < n - 2; ++i) {
            if (m >= 5 && i % 2 == 1)
                row[i] = false;
            else
                row[i] = true;
        }
        for (int i = 0; i < m - 2; ++i) {
            if (n >= 5 && i % 2 == 1)
                col[i] = false;
            else
                col[i] = true;
        }

        for (int i = 0; i < m; ++i)
            cout << '1';
        cout << '\n';
        for (int i = 0, limi = n - 2; i < limi; ++i) {
            cout << '1';
            for (int j = 0, limj = m - 2; j < limj; ++j) {
                if (i % 2 == j % 2) {
                    if (i % 2 != 1 && j % 2 != 1) {
                        cout << '*';
                        continue;
                    }

                    if (!row[i] || !col[j]) {
                        cout << '+';
                        row[i] = true; col[j] = true;
                    }
                    else
                        cout << '*';

                    // if (n >= 5 && m >= 5 && i != 1 && j != 1 && i != n - 2 && j != m - 2 && i == j)
                    //     cout << '+';
                    // else if (n >= 5 && m > n && i == n - 2 || i == n - 3 && j >= i)
                    //     cout << '+';
                    // else if (m >= 5 && n > m && j == m - 2 || j == m - 3 && i >= j)
                    //     cout << '+';
                    // else
                    //     cout << '*';
                }
                else
                    cout << '1';
            }
            cout << '1' << '\n';
        }
        for (int i = 0; i < m; ++i)
            cout << '1';
        cout << '\n';
    } else {
        
    }
}

/*

11111
1*1*1
11*11
1*1*1
11111

11111
1*1*1
11+11
1*1*1
11111

111111111
1*1*1*1*1
11*1+1*11
1*1*1*1*1
11*1+1*11
1*1*1*1*1
11*1+1*11
1*1*1*1*1
111111111

*/