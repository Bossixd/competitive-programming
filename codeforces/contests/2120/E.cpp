#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    int cars[n];
    for (int i = 0; i < n; ++i) cin >> cars[i];

    priority_queue<pair<int, int>> pqm;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pql;
    int sm = 0;

    for (int i = 0; i < n; ++i) {
        pqm.push(make_pair(cars[i], i));
        pql.push(make_pair(cars[i], i));
        sm += cars[i] * (cars[i] + 1) / 2;
    }

    int lm = -1;
    int ll = -2;

    while (true) {
        auto rm = pqm.top();
        pqm.pop();
        auto &[cm, im] = rm;

        auto rl = pql.top();
        pql.pop();
        auto &[cl, il] = rl;

        if (pqm.size() == 0) break;
        if (im == il) continue;

        if (cl != cars[il] || cm != cars[im]) {
            pqm.push(make_pair(cars[im], im));
            pql.push(make_pair(cars[il], il));
        }

        // transfer
        int t = cm - cl - 1 - k;
        if ((t + 1) / 2 == 0) {
            break;
        }

        int save;
        if (t % 2 == 1) save = (t + 1) * (t + 1) / 4;
        else save = t * (t + 2) / 4;

        sm -= save;

        cars[im] = cars[im] - ((t + 1) / 2);
        cars[il] = cars[il] + ((t + 1) / 2);

        pqm.push(make_pair(cars[im], im));
        pql.push(make_pair(cars[il], il));
    }
    cout << sm << '\n';
    // cout << "\n\n\n";
}

#undef int

int main()
{
    int N;
    cin >> N;
    while (N--)
        solve();
}
