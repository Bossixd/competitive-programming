#include <iostream>
#include <map>
#include <set>
#include <numeric>
#include <math.h>

using namespace std;

int main() {
    // #define int long long int
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, X, Y;
        cin >> N;
        pair<int, int> ants[N];
        map<string, pair<int, set<pair<int, int>>>> si;

        for (int n = 0; n < N; ++n) {
            cin >> X >> Y;
            ants[n] = pair<int, int>(X, Y);
        }

        int limit = (int) sqrt(N) - 1;
        bool done = false;

        for (int i = 0, limi = N - 1; i < limi; ++i) {
            for (int j = i + 1; j < N; ++j) {
                pair<int, int> anti = ants[i], antj = ants[j];
                double slope = ((double) anti.second - antj.second) / ((double) anti.first - antj.first);
                double yint = (slope * anti.first) - anti.second;
                string key = to_string(slope) + to_string(yint);

                if (si.find(key) == si.end()) {
                    set<pair<int, int>> empty_set;
                    si.insert(make_pair(key, make_pair(0, empty_set)));
                }

                if (si[key].second.find(make_pair(ants[i].first, ants[i].second)) == si[key].second.end()) {
                    si[key].first++;
                    si[key].second.insert(make_pair(ants[i].first, ants[i].second));
                }

                if (si[key].second.find(make_pair(ants[j].first, ants[j].second)) == si[key].second.end()) {
                    si[key].first++;
                    si[key].second.insert(make_pair(ants[j].first, ants[j].second));
                }
            }

            int mx = 0;
            set<pair<int, int>> unique;
            for (auto &[s, p] : si) {
                mx = max(mx, p.first);
                if (p.first != 1) {
                    for (auto &up : p.second) {
                        unique.insert(up);
                    }
                }
                if (p.first > limit) {
                    cout << "Case #" << t + 1 << ": " << N - p.first << '\n';
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        int mx = 0;
        if (!done) {
            for (auto &[s, p] : si)
                mx = max(mx, p.first);
            cout << "Case #" << t + 1 << ": " << N - mx << '\n';
        }
    }
}