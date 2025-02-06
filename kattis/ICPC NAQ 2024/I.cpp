#include <iostream>
using namespace std;

pair<int, int> direction[4] = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};

int main() {
    int N;
    cin >> N;

    char board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!(board[i][j] >= '0' && board[i][j] <= '4')) continue;

            int bulbs = 0;
            for (int k = 0; k < 4; k++) {
                int ni = i + direction[k].first;
                int nj = j + direction[k].second;
                if (ni >= 0 && ni < N && nj >= 0 && nj < N && board[ni][nj] == '?') bulbs++;
            }
            if (bulbs != board[i][j] - '0') {
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {   
        for (int j = 0; j < N; j++) {
            if (board[i][j] != '?') continue;

            for (int k = 0; k < 4; k++) {
                int ni = i + direction[k].first;
                int nj = j + direction[k].second;
                while (ni >= 0 && ni < N && nj >= 0 && nj < N && (board[ni][nj] == '.' || board[ni][nj] == '-' || board[ni][nj] == '?')) {
                    if (board[ni][nj] == '?') {
                        cout << 0 << '\n';
                        return 0;
                    }
                    board[ni][nj] = '-';
                    ni += direction[k].first;
                    nj += direction[k].second;
                }
            }

            // for (int i = 0; i < N; i++) {   
            //     for (int j = 0; j < N; j++) {
            //         cout << board[i][j];
            //     }
            //     cout << '\n';
            // } cout << '\n';

        }
    }

    // for (int i = 0; i < N; i++) {   
    //     for (int j = 0; j < N; j++) {
    //         cout << board[i][j];
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < N; i++) {   
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '.') {
                cout << 0 << '\n';
                return 0;
            }
        }
    }


    cout << 1 << '\n';
}