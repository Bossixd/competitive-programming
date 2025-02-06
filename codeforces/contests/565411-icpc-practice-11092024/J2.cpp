#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    int v[n];
    priority_queue<int, vector<int>, greater<int> > pq;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
        if (mp[v[i]] == 1) pq.push(v[i]);
    }

    int i = 0, j = n - 1;
    int mx = 0;
    int start, end;

    if ((j - i + 1) * pq.top() > mx) {
        start = i; end = j; mx = (j - i + 1) * pq.top();
    }

    while (i < j) {
        // Move i up
        ++i;
        --mp[v[i - 1]];
        if (mp[v[i - 1]] == 0) {
            mp.erase(v[i - 1]);
            while (mp.find(pq.top()) == mp.end()) {
                pq.pop();
            }
        }
        int scorei = (j - i + 1) * pq.top();
        if (pq.top() != v[i - 1]) pq.push(v[i - 1]);
        ++mp[v[i - 1]];
        --i;

        // Move j down
        --j;
        --mp[v[j + 1]];
        if (mp[v[j + 1]] == 0) {
            mp.erase(v[j + 1]);
            while (mp.find(pq.top()) == mp.end()) {
                pq.pop();
            }
        }
        int scorej = (j - i + 1) * pq.top();
        if (pq.top() != v[j + 1]) pq.push(v[j + 1]);
        ++mp[v[j + 1]];
        ++j;

        if (scorei > scorej) {
            // cout << "Move i\n";
            ++i;
            --mp[v[i - 1]];
            if (mp[v[i - 1]] == 0) {
                mp.erase(v[i - 1]);
                while (mp.find(pq.top()) == mp.end()) {
                    pq.pop();
                }
            }
        } else {
            // cout << "Move j\n";
            --j;
            --mp[v[j + 1]];
            if (mp[v[j + 1]] == 0) {
                mp.erase(v[j + 1]);
                while (mp.find(pq.top()) == mp.end()) {
                    pq.pop();
                }
            }
        }

        // for (int k = i; k <= j; ++k)
        //     cout << v[k] << ' ';
        // cout << '\n';
        // cout << pq.top() << '\n';
        // cout << '\n';

        if ((j - i + 1) * pq.top() > mx) {
            start = i; end = j; mx = (j - i + 1) * pq.top();
        }
    }
    cout << start + 1 << ' ' << end + 1 << ' ' << mx << '\n';
}