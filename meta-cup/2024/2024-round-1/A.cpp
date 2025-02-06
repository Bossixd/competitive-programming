#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

void test_case(int t);

int main() {
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #define int long long int
    // typedef pair<int, int> pii;
    int T;
    cin >> T;
    cout << "Test\n";
    for (int t = 0; t < T; ++t) {
        cout << t << '\n';
        test_case(t);
    }
}

// #define int long long int
// typedef pair<int, int> pii;

void test_case(int t) {
    int N, s, f;
    cin >> N;
    cout << N << '\n';
    
    // cout << "agagag\n";
    pair<int, int> time_window[N + 1];
    cout << "A\n";
    for (int n = 1; n <= N; ++n) {
        cin >> s >> f;
        time_window[n] = pair<int, int>(s, f);
    }

    pair<double, double> mmspeed[N + 1];
    double minmax = 1000001.0, maxmin = 0.0;
    cout << "B\n";
    for (int n = 1; n <= N; ++n) {
        mmspeed[n] = make_pair((double) time_window[n].first / (double) n, (double) time_window[n].second / (double) n);
        minmax = min(mmspeed[n].second, minmax);
        maxmin = max(mmspeed[n].first, maxmin);
    }
    double mn = 1.0 / minmax, mx = 1.0 / maxmin;
    cout << "Case #" << t + 1 << ": "; 
    if (mn <= mx) cout << mn << '\n';
    else cout << "-1\n";
    return;
}