#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long

template <typename T, typename U>
pair<T, U> mp(const T& first, const U& second) {
    return make_pair(first, second);
}

void solve() {
    int n;
    cin >> n;

    double sx = 0, sy = 0;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
        sx += v[i][0];
        sy += v[i][1];
    }

    sx /= (double) n;
    sy /= (double) n;

    int ssx = round(sx);
    int ssy = round(sy);

    priority_queue<vector<int>> q1, q2, q3, q4;
    vector<vector<int>> x, y, o;

    for (int i = 0; i < n; ++i) {
        if (v[i][0] > ssx) {
            if (v[i][1] > sy) {
                q1.push({abs(v[i][0] - ssx + v[i][1] - ssy), v[i][0], v[i][1], i});
            } else if (v[i][1] < ssy) {
                q4.push({{abs(v[i][0] - ssx + v[i][1] - ssy), v[i][0], v[i][1], i}});
            } else {
                // y-axis
                y.push_back({v[i][0], v[i][1], i});
            }
        } else if (v[i][0] < ssx) {
            if (v[i][1] > ssy) {
                q2.push({{-abs(v[i][0] - ssx + v[i][1] - ssy), v[i][0], v[i][1], i}});
            } else if (v[i][1] < ssy) {
                q3.push({{-abs(v[i][0] - ssx + v[i][1] - ssy), v[i][0], v[i][1], i}});
            } else {
                // y-axis
                y.push_back({v[i][0], v[i][1], i});
            }
        } else {
            if (v[i][1] == ssy) {
                // origin
                o.push_back({v[i][0], v[i][1], i});
            } else {
                // x-axis
                x.push_back({v[i][0], v[i][1], i});
            }
        }
    }
    
    cout << ssx << ' ' << ssy << "\n\n";

    // cout << "q1\n";
    // while (!q1.empty()) {
    //     cout << q1.top()[1] << ' ' << q1.top()[2] << '\n';
    //     q1.pop();
    // }
    // cout << '\n';

    // cout << "q2\n";
    // while (!q2.empty()) {
    //     cout << q2.top()[1] << ' ' << q2.top()[2] << '\n';
    //     q2.pop();
    // }
    // cout << '\n';

    // cout << "q3\n";
    // while (!q3.empty()) {
    //     cout << q3.top()[1] << ' ' << q3.top()[2] << '\n';
    //     q3.pop();
    // }
    // cout << '\n';

    // cout << "q4\n";
    // while (!q4.empty()) {
    //     cout << q4.top()[1] << ' ' << q4.top()[2] << '\n';
    //     q4.pop();
    // }
    // cout << '\n';

    // cout << "x\n";
    // for (auto i : x) {
    //     cout << i[0] << ' ' << i[1] << '\n';
    // }
    // cout << '\n';

    // cout << "y\n";
    // for (auto i : y) {
    //     cout << i[0] << ' ' << i[1] << '\n';
    // }
    // cout << '\n';


    for (int i = 0; i < x.size(); ++i) {
        cout << x[i][0] << ' ' << x[i][1] << '\n';
        if (x[i][1] > ssy) {
            if (q1.size() > q3.size()) {
                q2.push({-abs(x[i][0] - ssx + x[i][1] - ssy), x[i][0], x[i][1], x[i][2]});
            } else {
                q1.push({abs(x[i][0] - ssx + x[i][1] - ssy), x[i][0], x[i][1], x[i][2]});
            }
        } else {
            if (q2.size() > q4.size()) {
                q1.push({abs(x[i][0] - ssx + x[i][1] - ssy), x[i][0], x[i][1], x[i][2]});
            } else {
                q2.push({-abs(x[i][0] - ssx + x[i][1] - ssy), x[i][0], x[i][1], x[i][2]});
            }
        }
    }

    for (int i = 0; i < y.size(); ++i) {
        if (y[i][0] > ssx) {
            if (q1.size() > q4.size()) {
                q4.push({abs(y[i][0] - ssx + y[i][1] - ssy), y[i][0], y[i][1], y[i][2]});
            } else {
                q1.push({abs(y[i][0] - ssx + y[i][1] - ssy), y[i][0], y[i][1], y[i][2]});
            }
        } else {
            if (q2.size() > q3.size()) {
                q3.push({-abs(y[i][0] - ssx + y[i][1] - ssy), y[i][0], y[i][1], y[i][2]});
            } else {
                q2.push({-abs(y[i][0] - ssx + y[i][1] - ssy), y[i][0], y[i][1], y[i][2]});
            }
        }
    }

    for (int i = 0; i < o.size(); ++i) {
        if (q1.size() > q3.size()) {
            q3.push({-abs(o[i][0] - ssx + o[i][1] - ssy), o[i][0], o[i][1], o[i][2]});
        } else if (q1.size() < q3.size()) {
            q1.push({abs(o[i][0] - ssx + o[i][1] - ssy), o[i][0], o[i][1], o[i][2]});
        } else if (q2.size() > q4.size()) {
            q4.push({abs(o[i][0] - ssx + o[i][1] - ssy), o[i][0], o[i][1], o[i][2]});
        } else if (q2.size() < q4.size()) {
            q2.push({-abs(o[i][0] - ssx + o[i][1] - ssy), o[i][0], o[i][1], o[i][2]});
        } else {
            q4.push({abs(o[i][0] - ssx + o[i][1] - ssy), o[i][0], o[i][1], o[i][2]});
        }
    }

    cout << "q1\n";
    while (!q1.empty()) {
        cout << q1.top()[1] << ' ' << q1.top()[2] << '\n';
        q1.pop();
    }
    cout << '\n';

    cout << "q2\n";
    while (!q2.empty()) {
        cout << q2.top()[1] << ' ' << q2.top()[2] << '\n';
        q2.pop();
    }
    cout << '\n';

    cout << "q3\n";
    while (!q3.empty()) {
        cout << q3.top()[1] << ' ' << q3.top()[2] << '\n';
        q3.pop();
    }
    cout << '\n';

    cout << "q4\n";
    while (!q4.empty()) {
        cout << q4.top()[1] << ' ' << q4.top()[2] << '\n';
        q4.pop();
    }
    cout << '\n';

    // cout << q1.size() << ' ' << q2.size() << ' ' << q3.size() << ' ' << q4.size() << '\n';

    // int sm = 0;
    // while (!q4.empty()) {
    //     auto qq2 = q2.top(), qq4 = q4.top();
    //     q2.pop(); q4.pop();
    //     sm += abs(qq2[0] - qq4[0]) + abs(qq2[1] - qq4[1]);
    // }

    // while (!q1.empty()) {
    //     auto qq1 = q1.top(), qq3 = q3.top();
    //     q1.pop(); q3.pop();
    //     sm += abs(qq1[0] - qq3[0]) + abs(qq1[1] - qq3[1]);
    // }
    
    // cout << sm << '\n';
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
