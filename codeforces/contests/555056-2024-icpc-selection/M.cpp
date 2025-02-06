#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void test_case(int t);

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
        test_case(t);
}

void test_case(int t) {
    int N, M;
    cin >> N >> M;

    int r, w;
    pair<int, int> critics[M];

    for (int m = 0; m < M; ++m) {
        cin >> r >> w;
        critics[m] = make_pair(r, w);    
    }

    int R = N, W = 0;
    bool possible = false;
    while (R >= 0) {
        bool valid = true;
        for (int m = 0; m < M; ++m) {
            if (R < critics[m].first || W < critics[m].second) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            R--;
            W++;
            continue;
        }
        possible = true;
        break;
    }

    if (!possible) cout << "IMPOSSIBLE\n";
    else {
        for (r = 0; r < R; ++r) cout << 'R';
        for (w = 0; w < W; ++w) cout << 'W';
        cout << '\n';
    }
}