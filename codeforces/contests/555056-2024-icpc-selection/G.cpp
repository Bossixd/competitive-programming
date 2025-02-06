#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

unordered_map<int, set<int> > edges;
set<int> searched;
set< set<int> > psearched;
unordered_map<int, unordered_map<int, int> > dp;

int rec(int cur, int last, set<int> *pointsearch) {
    if (searched.find(cur) != searched.end()) return 0;
    searched.insert(cur);
    if (dp[cur].find(last) != dp[cur].end()) return dp[cur][last];

    int score = 1;
    for (auto edge : edges[cur]) {
        if (searched.find(edge) != searched.end()) continue;
        
        (*pointsearch).insert(edge);
        score += rec(edge, cur, pointsearch);
        (*pointsearch).erase(edge);
    }
    
    if (psearched.find(*pointsearch) != psearched.end()) return 0;
    psearched.insert(*pointsearch);

    dp[cur][last] = score;
    return dp[cur][last];
}

int main()
{
    int N, b;
    cin >> N;

    for (int n = 2; n <= N; ++n) {
        cin >> b;
        edges[b].insert(n);
        edges[n].insert(b);
    }

    // for (auto &[i, s] : edges) {
    //     cout << i << " : ";
    //     for (auto e : edges[i])
    //         cout << e << ' ';
    //     cout << '\n';
    // }

    int score = 0;
    for (int i = 1; i <= N; ++i) {
        searched.clear();
        set<int> pointsearch;
        pointsearch.insert(i);
        score += rec(i, -1, &pointsearch);
        // break;
        cout << "Searched: " << '\n';
        for (auto search : psearched) {
            for (auto i : search) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
    cout << score << '\n';
}