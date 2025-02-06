#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

void test_cast () {
    int N, S, F;
    cin >> N >> S >> F;

    int power[N + 1];
    int moves[N + 1];
    bool searched[N + 1];

    for (int i = 1; i <= N; ++i) {
        cin >> power[i];
        moves[i] = 10000001;
        searched[i] = false;
    }

    queue<int> q;
    moves[S] = 0;
    q.push(S);
    while (!q.empty()) {
        cout << "Moves: ";
        for (int i = 1; i <= N; ++i)
            cout << moves[i] << ' ';
        cout << '\n';
        int cur = q.front();
        q.pop();

        if (searched[cur]) continue;
        searched[cur] = true;

        for (int i = 1; i <= power[cur]; ++i) {
            if (cur - i >= 0 && min(power[cur], power[cur - i]) <= i) {
                moves[cur - i] = min(moves[cur] + 1, moves[cur - i]);
                q.push(cur - i);
            }
            if (cur + i < N && min(power[cur], power[cur + i]) <= i) {
                moves[cur + i] = min(moves[cur] + 1, moves[cur + i]);
                q.push(cur + i);
            }
        }
    }
    cout << "Moves: ";
    for (int i = 1; i <= N; ++i)
        cout << moves[i] << ' ';
    cout << '\n';
    cout << moves[F] << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        test_cast();
}