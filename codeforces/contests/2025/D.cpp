#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;



int mx_zero;
vector<pair<map<int, int>, map<int, int> > > *v;
unordered_map<int, unordered_map<int, int> > dp;

int rec(int cur_zero, int in) {
    cout << cur_zero << ' ' << in << '\n';
    if (cur_zero > mx_zero) return 0;

    if (dp.find(cur_zero) != dp.end()) {
        if (dp[cur_zero].find(in) != dp[cur_zero].end()) {
            return dp[cur_zero][in];
        }
    }
    int score = 0;
    map<int, int>::iterator it = (*v)[cur_zero].first.begin();
    if ((*v)[cur_zero].first.size() != 0) {
        while (it != (*v)[cur_zero].first.end()) {
            cout << it->first << ' ';
            if (in < it->first) break;
            ++it;
        }
        cout << "Test\n";
        score += prev(it)->second;
    }
    cout << 'a\n';

    if ((*v)[cur_zero].second.size() != 0) {
        it = (*v)[cur_zero].second.begin();
        while (it != (*v)[cur_zero].second.end()) {
            cout << it->first << ' ';
            if ((cur_zero - in) < it->first) break;
            ++it;
        }
        score += prev(it)->second;
    }
    cout << '\n';

    // cout << score << '\n';
    dp[cur_zero][in] = max(rec(cur_zero + 1, in + 1), rec(cur_zero + 1, in)) + score;
    return dp[cur_zero][in];
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<map<int, int>, map<int, int> > > vb(M + 1);
    int cur_zero = 0, b;
    for (int i = 0; i < N; ++i) {
        cin >> b;
        if (b == 0) {
            map<int, int>::iterator it;

            // Intel (first)
            if (vb[cur_zero].first.size() != 0) {
                it = vb[cur_zero].first.begin();
                ++it;
                while (it != vb[cur_zero].first.end()) {
                    it->second += prev(it)->second;
                    ++it;
                }
            }

            // Strength (second)
            if (vb[cur_zero].second.size() != 0) {
                it = vb[cur_zero].second.begin();
                ++it;
                while (it != vb[cur_zero].second.end()) {
                    it->second += prev(it)->second;
                    ++it;
                }
            }

            
            ++cur_zero;
        }
        else if (b > 0) vb[cur_zero].first[b]++;
        else vb[cur_zero].second[b * -1]++;
    }
    mx_zero = cur_zero;
    v = &vb;

    cout << rec(0, 0) << '\n';
}



// int mx_zero;
// vector<list<int> > *v;
// unordered_map<int, unordered_map<int, int> > dp;

// int rec(int cur_zero, int in) {
//     // cout << cur_zero << ' ' << in << '\n';
//     if (cur_zero > mx_zero) return 0;

//     if (dp.find(cur_zero) != dp.end()) {
//         if (dp[cur_zero].find(in) != dp[cur_zero].end()) {
//             return dp[cur_zero][in];
//         }
//     }
//     int score = 0;
//     list<int>::iterator it = (*v)[cur_zero].begin();
//     while (it != (*v)[cur_zero].end()) {
//         if (*it > 0 && in >= *it) ++score;
//         else if (*it < 0 && (cur_zero - in) >= *it * -1) ++score;
//         ++it;
//     }
//     // cout << score << '\n';
//     dp[cur_zero][in] = max(rec(cur_zero + 1, in + 1), rec(cur_zero + 1, in)) + score;
//     return dp[cur_zero][in];
// }

// int main() {
//     int N, M;
//     cin >> N >> M;

//     vector<list<int> > vb(M + 1);
//     int cur_zero = 0, b;
//     for (int i = 0; i < N; ++i) {
//         cin >> b;
//         if (b == 0) ++cur_zero;
//         else vb[cur_zero].push_back(b);
//     }
//     mx_zero = cur_zero;
//     v = &vb;

//     cout << rec(0, 0) << '\n';
// }



// int mx_zero;
// // vector<vector<int> > *v;
// // unordered_map<int, unordered_map<int, int> > dp;
// int v[5001][5001];
// int dp[5001][5001];

// int rec(int cur_zero, int in) {
//     // cout << cur_zero << ' ' << in << '\n';
//     if (cur_zero > mx_zero) return 0;

//     if (dp[cur_zero][in] != -1) return dp[cur_zero][in];

//     // if (dp.find(cur_zero) != dp.end()) {
//     //     if (dp[cur_zero].find(in) != dp[cur_zero].end()) {
//     //         return dp[cur_zero][in];
//     //     }
//     // }

//     int score = 0;
//     int cur = 0;
//     // while ((*v)[cur_zero][cur] != 0) {
//     //     if ((*v)[cur_zero][cur] > 0 && in >= (*v)[cur_zero][cur]) ++score;
//     //     else if ((*v)[cur_zero][cur] < 0 && (cur_zero - in) >= (*v)[cur_zero][cur] * -1) ++score;
//     //     ++cur;
//     // }
//     while (v[cur_zero][cur] != 0) {
//         if (v[cur_zero][cur] > 0 && in >= v[cur_zero][cur]) ++score;
//         else if (v[cur_zero][cur] < 0 && (cur_zero - in) >= v[cur_zero][cur] * -1) ++score;
//         ++cur;
//     }
//     // cout << score << '\n';
//     dp[cur_zero][in] = max(rec(cur_zero + 1, in + 1), rec(cur_zero + 1, in)) + score;
//     return dp[cur_zero][in];
// }


// int main() {
//     int N, M;
//     cin >> N >> M;

//     // vector<vector<int> > vb(N, vector<int>(N, 0));
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) {
//             v[i][j] = 0;
//             dp[i][j] = -1;
//         }
//     }
//     int cur_zero = 0, cur = 0, b;
//     for (int i = 0; i < N; ++i) {
//         cin >> b;
//         if (b == 0) {
//             ++cur_zero;
//             cur = 0;
//         } else {
//             // vb[cur_zero][cur] = b;
//             v[cur_zero][cur] = b;
//             ++cur;
//         }
//     }

//     mx_zero = cur_zero;
//     // for (auto i : vb) {
//     //     if (i[0] == 0) {
//     //         cout << "-\n";
//     //         continue;
//     //     }
//     //     for (auto j : i) {
//     //         if (j == 0) break;
//     //         cout << j << ' ';
//     //     }
//     //     cout << '\n';
//     // }
//     // v = &vb;

//     cout << rec(0, 0) << '\n';
// }




// vector<int> *v;

// unordered_map<int, unordered_map<int, unordered_map<int, int> > > dp;

// int rec(int cur, int in, int st) {
//     if (cur >= v->size()) return 0;
//     if (dp.find(cur) != dp.end()) {
//         if (dp[cur].find(in) != dp[cur].end()) {
//             if (dp[cur][in].find(st) != dp[cur][in].end()) {
//                 return dp[cur][in][st];
//             }
//         }
//     }
//     int score = 0;
//     while (cur < v->size() && (*v)[cur] != 0) {
//         if ((*v)[cur] > 0 && in >= (*v)[cur]) ++score;
//         else if ((*v)[cur] < 0 && st >= (*v)[cur] * -1) ++score;
//         ++cur;
//     }
//     dp[cur][in][st] = max(rec(cur + 1, in + 1, st), rec(cur + 1, in, st + 1)) + score;
//     return dp[cur][in][st];
// }

// int main() {
//     int N, M;
//     cin >> N >> M;

//     vector<int> vb(N);
//     for (int i = 0; i < N; ++i) cin >> vb[i];
//     v = &vb;

//     cout << rec(0, 0, 0) << '\n';
// }