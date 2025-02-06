#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define time first
#define index second.first
#define add second.second

struct Interval {
    int l, r, idx;
};

bool compare(Interval a, Interval b) {
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.r > b.r;
}

int main() {
    int N, s, a;
    cin >> N;
    vector<Interval> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].l >> v[i].r;
        v[i].r += v[i].l; v[i].idx = i;
    }

    sort(v.begin(), v.end(), compare);

    for (auto i : v) {
        cout << i.idx << ' ' << i.l << ' ' << i.r << '\n';
    }

    





    
    // int total = 0;
    // int lastTime = 0;
    // while (!pq.empty()) {
    //     pair<int, pair<int, int> > cur = pq.top();
    //     cout << pq.top().time << ' ' << pq.top().index << ' ' << pq.top().add << '\n';

    //     if (!st.empty() && cur.time == lastTime) {
    //         for (auto idx : st) {
    //             if (startTime[idx] != cur.time) continue;
    //             mp[idx]++;
    //         }
    //     }

    //     if (cur.add == 1) {
    //         st.insert(cur.index);
    //         mp[cur.index] = total;
    //     } else {
    //         st.erase(cur.index);
    //         // cout << "Erase: ";
    //         for (auto idx : st) {
    //             // cout << idx << ' ';
    //             if (startTime[idx] < startTime[cur.index]) continue;
    //             mp[idx]--;
    //         }
    //         // cout << '\n';
    //     }

    //     total += cur.add;

    //     cout << '\n' << "=-=-=-=-=-=-=-=-=-=-=-=-\n";
    //     for (auto &[idx, v] : mp) {
    //         cout << idx << ' ' << v << '\n';
    //     }
    //     cout << "=-=-=-=-=-=-=-=-=-=-=-=-\n";

    //     lastTime = cur.time;

    //     pq.pop();
    // }
}