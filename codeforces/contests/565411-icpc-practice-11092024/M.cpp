#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    char cur;
    Node* next[26];
};

struct L {
    int x, y;
    Node* node;
    int score;

    L(int _x, int _y, Node* _node, int _score) :
        x(_x),
        y(_y),
        score(_score),
        node(_node)
    {}
};

vector<pair<int, int> > direction;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    direction.push_back(make_pair(0, 1));
    direction.push_back(make_pair(0, -1));
    direction.push_back(make_pair(1, 0));
    direction.push_back(make_pair(-1, 0));

    char board[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j)
    //         cout << board[i][j];
    //     cout << '\n';
    // }

    string s;
    Node head;
    head.cur = '\0';
    for (int i = 0; i < k; ++i) {
        cin >> s;
        Node *curL = &head;
        for (char c : s) {
            if (curL->next[c - 'A'] != nullptr) {
                curL = curL->next[c - 'A'];
            } else {
                Node node;
                node.cur = c;
                curL->next[c - 'A'] = &node;
                curL = curL->next[c - 'A'];
            }
        }
    }

    cout << head.next['P']->next << '\n';

    queue<L*> q;

    for (int i = 0; i < m; ++i) {
        if (board[0][i] != 'X') {
            for (int j = 0; j < 26; ++j) {
                if (head.next[j] == nullptr) continue;
                if (char(j + 'A') == board[0][i]) {
                    q.push(new L(0, i, head.next[char(j + 'A')], 1));
                }
            }
        }
    }

    while (!q.empty()) {
        L *curL = q.front();
        q.pop();

        cout << "curL: " << curL->x << ' ' << curL->y << ' ' << curL->score << "\n";


        if (curL->x == n - 1) {
            cout << curL->score << '\n';
            return 0;
        }

        for (auto dir : direction) {
            int x = curL->x + dir.first;
            int y = curL->y + dir.second;
            if (x < 0 || x >= n) continue;
            if (y < 0 || y >= m) continue;
            cout << x << ' ' << y << '\n';
            if (board[x][y] == 'X') continue;
            cout << "Passed\n";
            bool pushed = false;
            cout << "At least here\n";
            for (int j = 0; j < 26; ++j) {
                cout << j << ' ';
                if (curL->node->next[j] == nullptr) continue;
                if (char(j + 'A') == board[x][y]) {
                    pushed = true;
                    q.push(new L(x, y, head.next[char(j + 'A')], curL->score + 1));
                }
            }
            cout << "??\n";
            if (!pushed)
                for (int i = 0; i < 26; ++i) {
                    if (head.next[i] == nullptr) continue;
                    if (char(i + 'A') == board[x][y])
                        q.push(new L(x, y, head.next[char(i + 'A')], curL->score + 1));
                }
        }
        cout << "Done\n";
    }
    cout << "impossible\n";
}