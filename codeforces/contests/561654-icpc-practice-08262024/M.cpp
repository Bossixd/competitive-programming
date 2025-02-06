#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    float x, y;
    cin >> N;
    set<pair<float, float> > s;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        s.insert(make_pair(x + 0.5, y));
        s.insert(make_pair(x - 0.5, y));
        s.insert(make_pair(x, y + 0.5));
        s.insert(make_pair(x, y - 0.5));
    }
    cout << s.size() * 0.5 << '\n';
}