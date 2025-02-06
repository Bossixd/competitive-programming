#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
    int N, s, c;
    cin >> N;
    
    unordered_map<int, vector<int> > mp;

    for (int i = 0; i < N; ++i) {
        cin >> s >> c;

        if (mp.find(s) == mp.end()) {
            mp[s] = vector<int>();
        }

        mp[s].push_back(c);
    }

    cout << setprecision(8) << fixed;

    double gears = 0;

    for (unordered_map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it) {
        sort(it->second.begin(), it->second.end());
        int i = 0, j = it->second.size() - 1;
        while (i < j) {
            gears += log((long double) (it->second[j]) / (long double) (it->second[i]));
            i++;
            j--;
        }
    }
    cout << gears << '\n';
}