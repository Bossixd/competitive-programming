#include <iostream>
using namespace std;
#define int long long

void cur() {
    int w, h;
    cin >> w >> h;

    int mn = min(w, h);
    int mx = max(w, h);
    char board[mn][mx];
    bool cur = true;

    int i, j;

    for (i = 0; i < mn; ++i) {
        for (j = 0; j < mx; ++j) {
            board[i][j] = '.';
        }
    }

    for (i = 0; i < mn; i += 2) {
        if (mn - i <= 1) break;
        if (mn - i == 3) break;
        for (j = 0; j < mx - (mx % 3); j += 3) {
            if (cur) {
                if ((j / 3) % 2 == 0) {
                    board[i][j] = 'A';
                    board[i][j + 1] = 'A';
                    board[i][j + 2] = 'B';
                    board[i + 1][j] = 'A';
                    board[i + 1][j + 1] = 'B';
                    board[i + 1][j + 2] = 'B';
                } else {
                    board[i][j] = 'C';
                    board[i][j + 1] = 'C';
                    board[i][j + 2] = 'D';
                    board[i + 1][j] = 'C';
                    board[i + 1][j + 1] = 'D';
                    board[i + 1][j + 2] = 'D';
                }
            } else {
                if ((j / 3) % 2 == 0) {
                    board[i][j] = 'C';
                    board[i][j + 1] = 'C';
                    board[i][j + 2] = 'D';
                    board[i + 1][j] = 'C';
                    board[i + 1][j + 1] = 'D';
                    board[i + 1][j + 2] = 'D';
                } else {
                    board[i][j] = 'A';
                    board[i][j + 1] = 'A';
                    board[i][j + 2] = 'B';
                    board[i + 1][j] = 'A';
                    board[i + 1][j + 1] = 'B';
                    board[i + 1][j + 2] = 'B';
                }
            }
        }
        cur = !cur;
    }

    cur = true;

    if (board[mn - 1][0] == '.' && board[mn - 2][0] == '.' && board[mn - 3][0] == '.') {
        for (i = 0; i < mx; i += 2) {
            if (mx - i < 2) continue;
            if (cur) {
                board[mn - 1][i] = 'X';
                board[mn - 2][i] = 'X';
                board[mn - 3][i] = 'Y';
                board[mn - 1][i + 1] = 'X';
                board[mn - 2][i + 1] = 'Y';
                board[mn - 3][i + 1] = 'Y';
            } else {
                board[mn - 1][i] = 'V';
                board[mn - 2][i] = 'V';
                board[mn - 3][i] = 'W';
                board[mn - 1][i + 1] = 'V';
                board[mn - 2][i + 1] = 'W';
                board[mn - 3][i + 1] = 'W';
            }
            cur = !cur;
        }
    }

    // if (board[0][mx - 1] == '.' && board[0][mx - 2] == '.') {
    //     for (i = 0; i < mn; i += 3) {
    //         if (mn - i < 3) continue;
    //         board[i][mx - 1] = 'E';
    //         board[i][mx - 2] = 'E';
    //         board[i + 1][mx - 1] = 'F';
    //         board[i + 1][mx - 2] = 'E';
    //         board[i + 2][mx - 1] = 'F';
    //         board[i + 2][mx - 2] = 'F';
    //     }
    // }

    if (board[mn - 2][mx - 1] == '.' && board[mn - 1][mx - 1] == '.' && board[mn - 1][mx - 2] == '.') {
        board[mn - 2][mx - 1] = 'Z';
        board[mn - 1][mx - 1] = 'Z';
        board[mn - 1][mx - 2] = 'Z';
    }

    if (mn == w)
        for (i = 0; i < mn; ++i) {
            for (j = 0; j < mx; ++j) {
                cout << board[i][j];
            }
            cout << '\n';
        }
    else
        for (i = 0; i < mx; ++i) {
            for (j = 0; j < mn; ++j) {
                cout << board[j][i];
            }
            cout << '\n';
        }
}

#undef int
int main() {
    int n;
    cin >> n;
    n--;
    cur();
    while (n--) {
        cout << '\n';
        cur();
    }
    return 0;
}