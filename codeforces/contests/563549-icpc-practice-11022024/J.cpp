#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define time first
#define index second.first
#define add second.second

unordered_map<int, int> mp;
unordered_map<int, unordered_set<int> > alibi;
unordered_map<int, int> startTime;
unordered_set<int> st;

struct Compare{
    bool operator()(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
        if (a.time != b.time) return a.time > b.time;
        if (a.add != b.add) return a.add > b.add;
        return startTime[a.index] < startTime[b.index];
    }
};

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, Compare > pq;

int main() {
    int N, s, a;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s >> a;
        pq.push(make_pair(s, make_pair(i, 1)));
        startTime[i] = s;
        pq.push(make_pair(s + a, make_pair(i, -1)));
    }
    
    int total = 0;
    int lastTime = 0;
    while (!pq.empty()) {
        pair<int, pair<int, int> > cur = pq.top();
        cout << pq.top().time << ' ' << pq.top().index << ' ' << pq.top().add << '\n';

        if (!st.empty() && cur.time == lastTime) {
            for (auto idx : st) {
                if (startTime[idx] != cur.time) continue;
                mp[idx]++;
            }
        }

        if (cur.add == 1) {
            st.insert(cur.index);
            mp[cur.index] = total;
        } else {
            st.erase(cur.index);
            // cout << "Erase: ";
            for (auto idx : st) {
                // cout << idx << ' ';
                if (startTime[idx] < startTime[cur.index]) continue;
                mp[idx]--;
            }
            // cout << '\n';
        }

        total += cur.add;

        cout << '\n' << "=-=-=-=-=-=-=-=-=-=-=-=-\n";
        for (auto &[idx, v] : mp) {
            cout << idx << ' ' << v << '\n';
        }
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-\n";

        lastTime = cur.time;

        pq.pop();
    }

    // cout << '\n';
    // for (auto &[idx, v] : mp) {
    //     cout << idx << ' ' << v << '\n';
    // }


    for (int i = 0; i < N; ++i)
        cout << mp[i] << ' ';
    cout << '\n';

    for (int i = 0; i < N; ++i) {
        cout << i << " | ";
        for (int idx : alibi[i]) {
            cout << idx << ' ';
        }
        cout << '\n';
    }
}