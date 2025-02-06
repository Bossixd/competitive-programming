#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_map<int, int> > dp;
int lim;

int combs(int N, unordered_set<int> *rev_edge) {
    int cur = N;
    int comb = 1;
    while (rev_edge[cur].size() == 1) {
        ++comb;
        for (int i : rev_edge[cur])
            cur = i;
    }
    int bcomb = 0;
    if (rev_edge[cur].size() > 1) {
        --comb;
        bcomb = 1;
        for (int i : rev_edge[cur])
            bcomb = (int) (((long long int) bcomb * (long long int) (combs(i, rev_edge) + 1)) % (long long int) 1000000007);
    }
    return comb + bcomb;
}

int combss(int N, int i, int *tail_combs) {
    if (dp.find(N) != dp.end())
        if (dp[N].find(i) != dp[N].end())
            return dp[N][i];
    if (N == 0) return 1;
    if (i >= lim) return 0;

    dp[N][i] = int(((long long int) combss(N, i + 1, tail_combs) % (long long int) 1000000007 + ((long long int) combss(N - 1, i + 1, tail_combs) * (long long int) tail_combs[i]) % (long long int) 1000000007) % (long long int) 1000000007);
    return dp[N][i];
}

int main() {
    int N;
    cin >> N;

    
    int edge[N];
    unordered_set<int> rev_edge[N];
    bool searched[N];
    pair<char, int> cls[N];
    vector<unordered_set<int> > groups;
    vector<unordered_set<int> > tail_roots;
    int cur_group = 0;
    int cur_tails = -1;

    for (int n = 0; n < N; ++n) {
        cin >> edge[n];
        --edge[n];
        rev_edge[edge[n]].insert(n);
        searched[n] = false;
    }

    for (int i = 0; i < N; ++i) {
        // Continue if already searched
        if (searched[i]) continue;

        // Create cur searched array
        bool cur_searched[N];
        for (int n = 0; n < N; ++n)
            cur_searched[n] = false;

        // Create Queue and Initialize value
        queue<int> q;
        q.push(i);

        // Create current and last node
        int fst = q.back();
        int cur = q.back();
        int last;

        // Join variable to see if the current path connects to a group
        bool join = false;

        // Go through the list until a group is created or a created group can be joined
        while (true) {
            // Set last to current
            last = cur;

            // Update current
            cur = q.back();

            // If current has been searched by this loop, we have found a loop
            if (cur_searched[cur]) break;

            // If current has not been searched by this loop, but has been found before, we have to join it.
            if (searched[cur]) {
                join = true;
                break;
            }

            // Set searched and current loop searched to true
            searched[cur] = true;
            cur_searched[cur] = true;

            // Push next edge onto queue
            q.push(edge[cur]);
        }

        // If not join
        if (!join) {
            // Join position is the last node in the queue
            int join_pos = q.back();

            // Add group and tail roots
            groups.push_back(unordered_set<int>());
            tail_roots.push_back(unordered_set<int>());

            int last = -1;

            while (q.front() != join_pos) {
                last = q.front();
                cls[q.front()] = make_pair('t', cur_tails);
                q.pop();
            }

            if (last != -1) {
                tail_roots[cur_group].insert(last);
                cls[last] = make_pair('t', cur_group);
            }

            while (q.size() != 1) {
                cls[q.front()] = make_pair('g', cur_group);
                groups[cur_group].insert(q.front());
                q.pop();
            }
            cur_group++;
        } else {
            if (cls[cur].first == 'g')
                tail_roots[cls[cur].second].insert(last);
            else if (cls[cur].second == 't') {
                while (q.front() != cur) {
                    cls[q.front()] = make_pair('t', cls[cur].second);
                    q.pop();
                }
            }
        }
    }

    int tail_combs[cur_group];
    lim = cur_group;
    
    for (int i = 0; i < cur_group; ++i) {

        tail_combs[i] = 1;
        if (tail_roots[i].empty()) continue;

        for (int tail : tail_roots[i]) {
            tail_combs[i] = (int) ((long long int) tail_combs[i] * (long long int) (combs(tail, rev_edge) + 1) % (long long int) 1000000007);
        }
    }

    long long int score = 0;
    for (int groups = 1; groups <= cur_group; ++groups) {
        score += int((long long int) combss(groups, 0, tail_combs) % (long long int) 1000000007);
    }
    cout << score % 1000000007 << '\n';
}

/*
4
2
3
4
3

1
2 < 1
3 < 2 4
4 < 3

2
3
1
5
4

1 < 3
2 < 1
3 < 2
4 < 5
5 < 4
*/