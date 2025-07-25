
#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n;

    unordered_map<int, vector<int>> edges;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    bool found = false;
    
    unordered_set<int> ss;
    queue<int> qq;
    qq.push(1);
    while (!qq.empty()) {
        auto node = qq.front();
        qq.pop();

        if (ss.find(node) != ss.end()) continue;
        ss.insert(node);

        if (edges[node].size() == 2) {
            found = true;
            a = node;
            break;
        }

        for (int neighbor : edges[node]) {
            if (ss.find(neighbor) != ss.end()) continue;
            qq.push(neighbor);
        }
    }

    if (!found) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    unordered_set<int> s;
    queue<pair<int, pair<int, bool>>> q;

    cout << edges[a][0] << ' ' << a << '\n';
    cout << a << ' ' << edges[a][1] << '\n';
    s.insert(a);

    q.push(make_pair(edges[a][0], make_pair(-1, false)));
    q.push(make_pair(edges[a][1], make_pair(-1, true)));
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        auto &[node, curr] = cur;
        auto &[par, color] = curr;

        if (s.find(node) != s.end()) continue;
        s.insert(node);

        if (par != -1) {
            if (color) {
                cout << par << ' ' << node << '\n';
            } else {
                cout << node << ' ' << par << '\n';
            }
        }

        for (int neighbor : edges[node]) {
            if (s.find(neighbor) != s.end()) continue;
            q.push(make_pair(neighbor, make_pair(node, !color)));
        }
    }
}

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
