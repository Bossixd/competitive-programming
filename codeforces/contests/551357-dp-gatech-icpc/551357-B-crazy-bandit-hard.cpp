#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

void run_test(int t) {
    int N, K;
    cin >> N >> K;
    int candies[N + 1];
    
    for (int n = 0; n < N; ++n)
        cin >> candies[n];
    candies[N] = 0;

    unordered_map<int, int> m;
    priority_queue<int, vector<int>, greater<int> > q;
    int mn;
    for (int i = 0; i < K; ++i) {
        m[candies[i]]++;
        q.push(candies[i]);
    }
    mn = q.top();

    for (int i = K; i <= N; ++i) {
        candies[i] = max(candies[i], mn);

        int index = i - K;
        m[candies[index]]--;

        m[candies[i]]++;
        q.push(candies[i]);

        mn = q.top();

        if (m[mn] == 0 && q.top() == mn) {
            q.pop();
            while (m[q.top()] == 0) q.pop();
            mn = q.top();
        }
    }

    cout << candies[N] << '\n';
    return;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) 
        run_test(t);
    return 0;
}

/*
[0 1 3] 2 4 8 2 7 3 5
priority queue -> 0 1 3
map -> 0 1 3
min -> 0

0 [1 3 2] 4 8 2 7 3 5
remove 0:
remove 0 from map
0 is min so remove from priority queue and check if 1 (next number) is in map.
since it is, 
update min

priority queue -> 0 1 3
map -> 0 1 3
min -> 0
*/
