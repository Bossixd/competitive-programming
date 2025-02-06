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

        int mx = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] != 'W') continue;

                int ws = 0;
                pii wsc;
                bool wsn = true;
                int score = 0;

                set<pii> s;
                queue<pii> q;

                q.push(make_pair(r, c));

                while (!q.empty()) {
                    pii cur = q.front();
                    q.pop();

                    if (cur.first < 0 || cur.first >= R) continue;
                    if (cur.second < 0 || cur.second >= C) continue;

                    if (s.find(cur) != s.end()) continue;

                    s.insert(cur);

                    if (board[cur.first][cur.second] == '.' && ws < 2) {
                        ws++;
                        wsc = cur;
                        if (ws >= 2) {
                            wsn = false;
                            score = 0;
                            break;
                        }
                        continue;
                    }

                    if (ws >= 2) {
                        wsn = false;
                        score = 0;
                        break;
                    }

                    if (board[cur.first][cur.second] == 'B') continue;

                    board[cur.first][cur.second] = '.';

                    score++;

                    for (pii dir : dirs) {
                        pii next = make_pair(cur.first + dir.first, cur.second + dir.second);
                        if (s.find(next) != s.end()) continue;
                        q.push(next);
                    }
                }

                if (!wsn) continue;
                for (pii dir : dirs) {
                    int b_score = 0;

                    if (wsc.first + dir.first < 0 || wsc.first + dir.first >= R) continue;
                    if (wsc.second + dir.second < 0 || wsc.second + dir.second >= C) continue;

                    if (s.find(make_pair(wsc.first + dir.first, wsc.second + dir.second)) != s.end()) continue;

                    if (board[wsc.first + dir.first][wsc.second + dir.second] == 'W') {
                        q.push(make_pair(wsc.first + dir.first, wsc.second + dir.second));
                        s.insert(q.front());

                        while (!q.empty()) {
                            pii cur = q.front();
                            q.pop();

                            if (cur.first < 0 || cur.first >= R) continue;
                            if (cur.second < 0 || cur.second >= C) continue;

                            s.insert(cur);

                            if (board[cur.first][cur.second] == '.') {
                                b_score = 0;
                                break;
                            }

                            if (board[cur.first][cur.second] == 'B') continue;

                            board[cur.first][cur.second] = '.';

                            b_score += 1;

                            for (pii dir : dirs) {
                                pii next = make_pair(cur.first + dir.first, cur.second + dir.second);
                                if (s.find(next) != s.end()) continue;
                                q.push(next);
                            }
                        }
                        score += b_score;
                    }
                }

                mx = max(mx, score);
            }
        }


        cout << "Case #" << n + 1 << ": " << mx << '\n';
    }
}