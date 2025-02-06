#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int v1[1000], b;
    unordered_map<int, int> mp;
    for (int i = 0; i < 1000; ++i) {
        cin >> v1[i];
        cin >> b;
        if (mp.find(b) == mp.end()) {
            mp[b] = 1;
        } else {
            mp[b]++;
        }
    }

    int s = 0;
    for (int i = 0; i < 1000; ++i) {
        s += mp[v1[i]] * v1[i];
    }
    cout << s << endl;
    return 0;
}