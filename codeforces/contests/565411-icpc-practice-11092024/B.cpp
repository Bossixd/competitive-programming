#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int pages[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> pages[i];

    unordered_map<int, int> parent;
    unordered_map<int, unordered_set<int> > child;
    unordered_map<int, string> path;

    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        parent[b] = a;
        child[a].insert(b);
    }

    for (int i = 1; i <= n; ++i) {
        int cur = i;
        string cur_path = "";
        while (parent.find(cur) != parent.end()) {
            cur_path += to_string(cur) + " ";
            cur = parent[cur];
        }
        cur_path += to_string(cur);
        path[i] = cur_path;
    }

    int leaf[n + 1];
    int leaves = 0;

    for (int i = 1; i <= n; ++i) {
        if (child[i].size() == 0)
            leaf[leaves++] = i;

        if (parent.find(i) != parent.end())
            continue;
        queue<pair<int, int> > q;
        q.push(make_pair(i, 0));
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            pages[cur.first] = cur.second + pages[cur.first];

            for (auto c : child[cur.first]) {
                q.push(make_pair(c, pages[cur.first]));
            }
        }
    }

    // for (int i = 0; i < leaves; ++i) {
    //     cout << leaf[i] << ' ';
    // }
    // cout << '\n';

    // for (int i = 1; i <= n; ++i) {
    //     cout << child[i].size() << ' ';
    // }
    // cout << '\n';

    // for (int i = 1; i <= n; ++i) {
    //     cout << pages[i] << ' ';
    // }
    // cout << '\n';
    // cout << '\n';

    int mn = 100000000;

    for (int i = 0; i < leaves - 1; ++i) {
        for (int j = i + 1; j < leaves; ++j) {
            int score = 0;
            int l1 = leaf[i], l2 = leaf[j];
            int s1 = path[l1].size() - 1, s2 = path[l2].size() - 1;

            while (s1 >= 0 && s2 >= 0 && path[l1][s1] == path[l2][s2]) {
                --s1; --s2;
            }
            while (s1 < path[l1].size() && path[l1][s1] != ' ') ++s1;
            while (s2 < path[l2].size() && path[l2][s2] != ' ') ++s2;
            ++s1; ++s2;

            if (s1 >= path[l1].size()) {
                score += pages[leaf[i]] + pages[leaf[j]];
            } else {
                int b = s1;
                while (b < path[l1].size() && path[l1][b] != ' ') ++b;
                int join = stoi(path[l1].substr(s1, b - s1));
                score -= pages[join];

                score += pages[leaf[i]] + pages[leaf[j]];
            }

            mn = min(mn, score);
        }
    }
    cout << mn << '\n';
}