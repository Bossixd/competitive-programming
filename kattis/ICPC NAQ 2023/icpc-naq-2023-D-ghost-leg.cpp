#include <iostream>
#include <vector>
using namespace std;

int main() {
    #define pii pair<int, int>
    int N, M, A;
    cin >> N >> M;
    
    vector<pii> rungs(M);

    for (int m = 0; m < M; ++m) {
        cin >> A;
        rungs[M - m - 1] = make_pair(A, A + 1);
    }

    for (int n = 0; n < N; ++n) {
        int cur = n + 1;
        for (pii rung : rungs) {
            if (cur == rung.first)
                cur = rung.second;
            else if (cur == rung.second)
                cur = rung.first;
        }
        cout << cur << '\n';
    }
}

/*
4 5
1
2
1
3
2
*/