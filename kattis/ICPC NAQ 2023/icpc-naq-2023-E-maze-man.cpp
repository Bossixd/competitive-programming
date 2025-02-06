#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <string>
using namespace std;

typedef pair<int, int> pii;

pii directions[4] = {
    make_pair(0, 1),
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(-1, 0)
};

int main() {
    int N, M;
    cin >> N >> M;

    char maze[N + 1][M + 1];
    queue<pii> players;
    int player_count = 0;

    int dots = 0;

    string line;
    cin.ignore();

    for (int n = 0; n < N; ++n) {
        getline(cin, line);

        for (int m = 0; m < M; ++m) {
            maze[n][m] = line[m];
            if (maze[n][m] == '.') ++dots;
            if (maze[n][m] != 'X' && maze[n][m] != '.' && maze[n][m] != ' ') {
                players.push(make_pair(n, m));
                player_count++;
            }
        }
    }
    
    int player_used = player_count;
    for (int player_index = 0; player_index < player_count; ++player_index) {
        queue<pii> q;
        q.push(players.front());
        players.pop();

        pii cur = q.front();
        if (cur.first < 0 || cur.first >= N) continue;
        if (cur.second < 0 || cur.second >= M) continue;
        char cur_player = maze[cur.first][cur.second];
        bool chosen = false;

        for (int i = 0; i < 4; ++i) {
            pii dir = directions[i];
            pii n = make_pair(cur.first + dir.first, cur.second + dir.second);

            if (n.first < 0 || n.first >= N) continue;
            if (n.second < 0 || n.second >= M) continue;

            if (maze[n.first][n.second] == 'X') continue;

            if (maze[n.first][n.second] != cur_player && maze[n.first][n.second] >= 'A' && maze[n.first][n.second] <= 'W') continue;

            chosen = true;
            break;
        }

        if (!chosen) {
            --player_used;
            continue;
        }

        int dots_added = 0;

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            if (maze[cur.first][cur.second] == 'X') continue;

            if (maze[cur.first][cur.second] == '.') {
                --dots;
                ++dots_added;
            }

            if (maze[cur.first][cur.second] != cur_player && maze[cur.first][cur.second] >= 'A' && maze[cur.first][cur.second] <= 'Z') continue;

            maze[cur.first][cur.second] = 'X';

            for (int i = 0; i < 4; ++i) {
                pii dir = directions[i];
                pii n = make_pair(cur.first + dir.first, cur.second + dir.second);
                if (n.first < 0 || n.first >= N) continue;
                if (n.second < 0 || n.second >= M) continue;
                q.push(n);
            }
        }

        if (dots_added == 0) --player_used;
    }
    cout << player_used << ' ' << dots << '\n';
    return 0;
}

/*
10 20
XXXXXXXAXXXXXXXBXXXX
X.. ..X.X...... ...X
X.XXX...X.X.XXXXXX.X
X.X.XXXXX.X.X....X.X
X.X... ...X.X.XX.X.X
X.X.X.XXXXXXX.XX.X.X
X.X.X.X...X...X....X
X.X.X.XXXXXXX.XXXX.X
X...X.X X.. ..X..X.X
XXXXXXXDXXXXXXXXCXXX
*/