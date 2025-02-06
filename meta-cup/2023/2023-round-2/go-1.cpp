#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int T;
    cin >> T;

    pii dirs[] = {
        make_pair(0, 1),
        make_pair(0, -1),
        make_pair(1, 0),
        make_pair(-1, 0)
    };

    for (int n = 0; n < T; n++) {
        int R, C;
        cin >> R >> C;

        char board[R][C];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> board[r][c];
            } 
        }

        bool done = false;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] != 'W') continue;

                int ws = 0;

                set<pii> s;
                queue<pii> q;

                q.push(make_pair(r, c));

                while (!q.empty()) {
                    pii cur = q.front();
                    q.pop();

                    if (s.find(cur) != s.end()) continue;

                    if (cur.first < 0 || cur.first >= R) continue;
                    if (cur.second < 0 || cur.second >= C) continue;

                    s.insert(cur);

                    if (board[cur.first][cur.second] == '.') {
                        ws++;
                        continue;
                    }

                    if (board[cur.first][cur.second] == 'B') continue;

                    board[cur.first][cur.second] = '.';

                    for (pii dir : dirs) {
                        pii next = make_pair(cur.first + dir.first, cur.second + dir.second);
                        if (s.find(next) != s.end()) continue;
                        q.push(next);
                    }
                }
                if (ws == 1) {
                    done = true;
                    break;
                }
            }
            if (done) break;
        }

        if (done) cout << "Case #" << n + 1 << ": " << "YES" << '\n';
        else cout << "Case #" << n + 1 << ": " << "NO" << '\n';
    }
}
