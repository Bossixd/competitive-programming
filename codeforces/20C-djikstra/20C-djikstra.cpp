#include <iostream>
#include <tuple>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int> > edges[N];
    int S, E, L;
    for (int m = 0; m < M; ++m) {
        cin >> S >> E >> L;
        edges[S].push_back(make_pair(E, L));
        edges[E].push_back(make_pair(S, L));
    }

    priority_queue<tuple<int, string, int> > q;
    set<int> visited;
    q.push(make_tuple(0, "1", 1));
    tuple<int, string, int> f;
    while (!q.empty()) {
        tuple<int, string, int> cur = q.top();
        q.pop();

        int index = get<2>(cur); 
        string path = get<1>(cur);
        int distance = get<0>(cur);
        
        if (index == N) {
            f = cur;
            break;
        }
        if (visited.find(index) != visited.end()) continue;

        visited.insert(index);

        for (pair<int, int> p : edges[index]) {
            q.push(make_tuple(distance + p.second, path.append(" " + to_string(p.first)), p.first));
        }
        cout << get<1>(cur) << '\n';
    }
    return 0;
}