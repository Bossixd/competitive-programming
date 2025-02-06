#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

pii directions[4] = {
    make_pair(0, 1),
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(-1, 0)
};

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    char room[N][M];
    int steps[N][M];

    queue<pii> q;

    for (int n = 0; n < N; ++n)
        for (int m = 0; m < M; ++m) {
            cin >> room[n][m];
            steps[n][m] = 0;
            if (room[n][m] == 'E') {
                q.push(make_pair(n, m));
                room[n][m] = 'X';
            }
        }
    
    int cnt = 0;
    pii cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        int score = steps[cur.first][cur.second];

        for (int i = 0; i < 4; ++i) {
            pii nxt = directions[i];
            nxt.first += cur.first;
            nxt.second += cur.second;

            if (nxt.first < 0 || nxt.first >= N) continue;
            if (nxt.second < 0 || nxt.second >= M) continue;

            if (room[nxt.first][nxt.second] == '#' || room[nxt.first][nxt.second] == 'X') continue;

            steps[nxt.first][nxt.second] = max(score + 1, steps[nxt.first][nxt.second]);

            if (room[nxt.first][nxt.second] == 'P') {
                ++score;
                if (steps[nxt.first][nxt.second] <= S)
                    cnt++;
            }

            room[nxt.first][nxt.second] = 'X';

            q.push(nxt);
        }
    }

    // for (int n = 0; n < N; ++n) {
    //     for (int m = 0; m < M; ++m)
    //         cout << steps[n][m] << ' ';
    //     cout << '\n';
    // }

    cout << cnt << '\n';
}