#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    #define int long long int

    int N, M;
    cin >> N >> M;

    int houses[N];
    vector<int> shops(M);
    vector<pair<int, int> > zones(N * 2 + 1);
    for (int n = 0; n < N; ++n)
        cin >> houses[n];

    for (int m = 0; m < M; ++m)
        cin >> shops[m];

    sort(shops.begin(), shops.end());

    int m;
    for (int n = 0; n < N; ++n) {
        for (int aaa = 0; aaa < 1; ++aaa) {
            int l = 0, r = M - 1;

            if (n * 100 <= shops[l]) {
                m = l;
                break;
            }
            if (n * 100 >= shops[r]) {
                m = r;
                break;
            }

            while (l <= r) {
                int m = l + (r - l) / 2;

                if (shops[m] == n * 100) {
                    l = m;
                    r = m;
                    break;
                }

                if (shops[m] < n * 100) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            m = (abs(shops[l] - n * 100) < abs(shops[r] - n * 100) ? l : r);
        }
        
        int d = abs(n * 100 - shops[m]);
        zones[2 * n] = make_pair(n * 100 + d, houses[n] * -1);
        zones[2 * n + 1] = make_pair(n * 100 - d, houses[n]);
    }

    sort(zones.begin(), zones.end());

    int mx = 0;
    int cur = 0;
    for (auto &[_, people] : zones) {
        cur += people;
        mx = max(mx, cur);
    }
    cout << mx << '\n';
}