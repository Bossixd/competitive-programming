#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v1(1000), v2(1000);
    for (int i = 0; i < 1000; ++i) {
        cin >> v1[i] >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int s = 0;
    for (int i = 0; i < 1000; ++i) {
        s += abs(v1[i] - v2[i]);
    }
    cout << s << endl;
    return 0;
}