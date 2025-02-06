#include <iostream>
using namespace std;

int N, M;
int e[2000], a[2000], act[2000];

int scoring(int n) {
    n = abs(n);
    if (n >= 0 && n <= 15) return 7;
    else if (n > 15 && n <= 23) return 6;
    else if (n > 23 && n <= 43) return 4;
    else if (n > 43 && n <= 102) return 2;
    else return 0;
}

int rec(int i) {
    if (i == M) return 0;

    // Binary Search to find
    int l = 0, r = N - 1;
    int choose = -1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (act[i] == e[mid]) {
            choose = mid;
            break;
        }
        if (act[i] > e[mid]) {
            choose = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << e[choose] << ' ' << choose << '\n';
    // return 0;

    int index, score1 = 0, score2 = 0, score3 = 0, inc;
    if (choose != N - 1) {
        index = choose + 1;
        while (index < N && a[index] == -1) index++;
        if (index < N && a[index] != -1) {
            inc = a[index];
            if (scoring(inc - e[i]) != 0) {
                a[index] = -1;
                score1 = scoring(inc - e[i]) + rec(i + 1);
                cout << "A: " << i << ' ' << 1 << ' ' << score1 <<'\n';
                for (int i = 0; i < N; ++i)
                    cout << a[i] << ' ';
                cout << '\n';
                a[index] = inc;
            }
        }
    }
    if (choose != -1) {
        index = choose;
        while (index >= 0 && a[index] == -1) index--;
        if (index >= 0 && a[index] != -1) {
            inc = a[index];
            if (scoring(inc - e[i]) != 0) {
                a[index] = -1;
                score2 = scoring(inc - e[i]) + rec(i + 1);
                cout << "A: " << i << ' ' << 2 << ' ' << score1 <<'\n';
                for (int i = 0; i < N; ++i)
                    cout << a[i] << ' ';
                cout << '\n';
                a[index] = inc;
            }
        }
    }

    score3 = rec(i + 1);
    cout << "A: " << i << ' ' << 3 << ' ' << score1 <<'\n';
    for (int i = 0; i < N; ++i)
        cout << a[i] << ' ';
    cout << '\n';
    
    // cout << "A: " << i << ' ' << max(score1, max(score2, score3)) <<'\n';
    // cout << max(score1, max(score2, score3)) << '\n';
    // if (score1 == max(score1, max(score2, score3))) cout << "1\n";
    // if (score2 == max(score1, max(score2, score3))) cout << "2\n";
    // if (score3 == max(score1, max(score2, score3))) cout << "3\n";
    return max(score1, max(score2, score3));
}

int main() {
    cin >> N >> M;
    
    for (int n = 0; n < N; ++n) {
        cin >> a[n];
        act[n] = a[n];
    }

    for (int m = 0; m < M; ++m) {
        cin >> e[m];
    }

    cout << rec(0) << '\n';
}