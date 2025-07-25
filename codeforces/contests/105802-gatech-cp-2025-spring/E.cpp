#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <string>
using namespace std;

#define int long long

void cur() {
    // cout << "+====+====+====+====+====\n";
    int n, m, k;
    cin >> n >> m >> k;

    int u, v, w;
    unordered_map<int , unordered_map<int, int> > edges;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges[u][v] = w;
        edges[v][u] = w;
    }

    vector<int> regions(n + 1);
    for (int i = 1; i <= n; ++i) cin >> regions[i];

    // cost, k, node
    priority_queue<vector<int>, std::vector<vector<int>>, std::greater<vector<int>>> pq;
    vector<int> vec = {0, k, 1};
    unordered_set<string> searched;
    pq.push(vec);
    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();
        int cost = cur[0];
        int cur_k = cur[1];
        int node = cur[2];

        if (searched.find(to_string(cur_k) + "_" + to_string(node)) != searched.end())
            continue;
        searched.insert(to_string(cur_k) + "_" + to_string(node));

        if (node == n) {
            cout << cost << '\n';
            return;
        }

        for (auto i : edges[node]) {
            vec = {cost + i.second, cur_k, i.first};
            pq.push(vec);
        }

        if (cur_k == 0) continue;
        for (int i = 1; i <= n; ++i) {
            if (searched.find(to_string(cur_k - 1) + "_" + to_string(i)) != searched.end()) continue;
            if (i == node) continue;
            
            // cout << "Flight to " << i << " costs " << cost + abs(regions[i] - regions[node]) << '\n';
            // cout << "Nodes: " << i << ' ' << node << '\n';
            // cout << "Regions: " << regions[i] << ' ' << regions[node] << '\n';
            vec = {cost + abs(regions[i] - regions[node]), cur_k - 1, i};
            pq.push(vec);
        }
    }
}

#undef int

int main() {
    int n;
    cin >> n;
    while (n--) {
        cur();
    }
    return 0;
}