#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, G;
        cin >> N >> G;

        vector<int> E(N);
        int b;
        int mn = 1000001;
        int d = 0;
        for (int i = 0; i < N; ++i) {
            cin >> E[i];
            if (abs(E[i] - G) < mn) {
                mn = abs(E[i] - G);
                d = E[i];
            } else if (abs(E[i] - G) == mn && E[i] > d)
                d = E[i];
        }

        sort(E.begin(), E.end());

        // Binary Search
        int l = 0;
        int h = N - 1;
        int m;
        int index = -1;
        do {
            m = (h + l) / 2;
            if (d < E[m])
                h = m;
            else if (d > E[m])
                l = m;
            else {
                index = m;
                break;
            }
        } while (l < h - 1);

        if (index == -1) {
            if (E[l] == d) index = l;
            else index = h;
        }

        cout << "Case #" << t + 1 << ": " << N - index << ' ' << mn << '\n';
    }
}