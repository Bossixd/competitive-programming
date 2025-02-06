#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);

    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];

    vector<int>::iterator max_r_it = max_element(r.begin(), r.end());
    vector<int>::iterator min_l_it = min_element(l.begin(), l.end());

    int max_r = *max_r_it;
    int min_l = *min_l_it;

    for (int i = 0; i < n; ++i) {
        if (l[i] == min_l && r[i] == max_r) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}