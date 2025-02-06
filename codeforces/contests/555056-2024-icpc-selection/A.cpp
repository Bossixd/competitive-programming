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
    int N;
    cin >> N;

    int A, B;
    int score[11];
    for (int i = 1; i < 11; ++i)
        score[i] = -1;

    for (int n = 0; n < N; ++n) {
        cin >> A >> B;
        score[B] = max(score[B], A);
    }

    int mx = 0;
    for (int i = 1; i < 11; ++i) {
        if (score[i] == -1) {
            cout << "MOREPROBLEMS\n";
            return;
        }

        mx += score[i];
    }

    cout << mx << '\n';
    return;
}