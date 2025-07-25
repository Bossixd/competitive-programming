#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
#define int long long

unordered_set<string> seen;

int fight(vector<vector<int> > nmons, vector<vector<int> > mmons, vector<int> order) {
    int i = 0, j = 0;
    while (true) {
        string s = "";
        for (int k = 0; k < (int) nmons.size(); ++k) {
            s += to_string(nmons[order[k]][0]) + " " + to_string(nmons[order[k]][1]) + "_";
        }
        for (int k = 0; k < (int) mmons.size(); ++k) {
            s += to_string(mmons[k][0]) + " " + to_string(mmons[k][1]) + "_";
        }

        if (seen.find(s) != seen.end()) return 0;
        seen.insert(s);
        
        int our_dmg = nmons[order[i]][1] / mmons[j][0];
        int enm_dmg = mmons[j][1] / nmons[order[i]][0];

        int rounds = min(our_dmg, enm_dmg);
        if (rounds == 0) rounds = 1;

        nmons[order[i]][1] -= mmons[j][0] * rounds;
        mmons[j][1] -= nmons[order[i]][0] * rounds;

        if (nmons[order[i]][1] <= 0) ++i;
        if (mmons[j][1] <= 0) ++j;

        if (i == (int) nmons.size() && j == (int) mmons.size()) return 0;
        if (i == (int) nmons.size()) return -1;
        if (j == (int) mmons.size()) return 1;
    }
}

void cur() {
    // us, enemy
    int n, m;
    cin >> n >> m;

    vector<vector<int> > nmons(n, vector<int>(2));
    vector<vector<int> > mmons(m, vector<int>(2));

    for (int i = 0; i < n; ++i) cin >> nmons[i][0];
    for (int i = 0; i < n; ++i) cin >> nmons[i][1];

    for (int i = 0; i < m; ++i) cin >> mmons[i][0];
    for (int i = 0; i < m; ++i) cin >> mmons[i][1];

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) nums[i] = i;
    
    bool win = false;
    bool draw = false;

    do {
        int res = fight(nmons, mmons, nums);
        if (res == 0) draw = true;
        if (res == 1) {
            cout << "WIN\n";
            return;
        }
    } while (next_permutation(nums.begin(), nums.end()));

    if (win) cout << "WIN\n";
    else if (draw) cout << "TIE\n";
    else cout << "LOSE\n";

    return;
}

#undef int

int main() {
    int n;
    cin >> n;
    while (n--) {
        cur();
    }
    return 0;
}