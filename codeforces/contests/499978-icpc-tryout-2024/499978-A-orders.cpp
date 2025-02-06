#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test_case();

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
        test_case();
}

void test_case() {
    #define int long long int
    int N, K;
    cin >> N >> K;

    vector<pair<int, int> > vec(N, make_pair(-1, -1));
    for (int i = 0; i < N; ++i) {
        int date, amount;
        cin >> date >> amount;
        vec[i].first = date;
        vec[i].second = amount;
    }

    sort(vec.begin(), vec.end());

    int taken = 0;
    int total = 0;
    for (auto p : vec) {
        total = K * p.first;
        if (total - taken < p.second) {
            cout << "No\n";
            return;
        }
        taken += p.second;
    }
    cout << "Yes\n";
}