#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;

void test_case();

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
        test_case();
}

void test_case() {
    #define int long long int
    int N, M, b;
    cin >> N >> M;

    int edges[N + 1];
    set<int> rev_edges[N + 1];
    bool critical[N + 1];
    int critical_nodes[N + 1];
    char chars[N + 1];

    for (int n = 0; n < N; ++n) {
        cin >> edges[n + 1];
        rev_edges[edges[n + 1]].insert(n + 1);
        critical[n] = false;
        critical_nodes[n] = 0;
        chars[n] = '-';
    }

    critical[N] = false;
    critical_nodes[N] = 0;
    chars[N] = '-';

    for (int m = 0; m <= M; ++m) {
        cin >> b;
        critical[b] = true;
    }

    /*
    DFS from the top node to determine width paths
    */
    stack<int> pre_s, s;
    set<int> searched;
    
    pre_s.push(0);
    while (!pre_s.empty()) {
        int cur = pre_s.top();
        pre_s.pop();
        s.push(cur);

        for (auto i : rev_edges[cur]) {
            pre_s.push(i);
        }
    }

    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (cur == 0) break;

        if (critical[cur]) critical_nodes[edges[cur]] += critical_nodes[cur] + 1;
        else critical_nodes[edges[cur]] += critical_nodes[cur];
    }

    /*
    BFS from the top node
    If critical, form characters from critical node
    */
    unordered_map<int, char> child_chars;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << '\n';
        q.pop();

        if (critical[cur]) { // Current Node is Critical
            int nxt = cur;
            // cout << cur << ' ' << chars[nxt] << '\n';
            while (nxt != 0 && chars[nxt] == '-') {
                if (child_chars.find(edges[nxt]) == child_chars.end()) {
                    child_chars[edges[nxt]] = 'a' - 1;
                }
                // cout << "Update: " << edges[nxt] << '\n';
                child_chars[edges[nxt]]++;
                chars[nxt] = child_chars[edges[nxt]];
                nxt = edges[nxt];
            }
        }

        priority_queue<pair<int, int> > pq;
        for (auto i : rev_edges[cur]) {
            pq.push(make_pair(critical_nodes[i], i));
        }
        while (!pq.empty()) {
            q.push(pq.top().second);
            pq.pop();
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << chars[i];
    cout << '\n';
}

/*
a aa ab aba abb
a aa ab aaa aab
*/