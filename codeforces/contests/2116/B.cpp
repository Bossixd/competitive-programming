#include <iostream>
#include <unordered_map>

using namespace std;

int twos[100000];

void run() {
    int n;
    cin >> n;

    int p[n];
    int q[n];

    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) cin >> q[i];

    int pmx[n];
    int qmx[n];

    pmx[0] = 0;
    int pmxn = p[0], pmxid = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] > pmxn) {
            pmxn = p[i];
            pmxid = i;
        }
        pmx[i] = pmxid;
    }

    qmx[0] = 0;
    int qmxn = q[0], qmxid = 0;
    for (int i = 0; i < n; ++i) {
        if (q[i] > qmxn) {
            qmxn = q[i];
            qmxid = i;
        }
        qmx[i] = qmxid;
    }

    for (int i = 0; i < n; ++i) {
        int mx;
        if (p[pmx[i]] > q[qmx[i]]) {
            mx = twos[p[pmx[i]]] + twos[q[i - pmx[i]]];
        } else if (p[pmx[i]] < q[qmx[i]]) {
            mx = twos[q[qmx[i]]] + twos[p[i - qmx[i]]];
        } else {
            if (p[i - qmx[i]] > q[i - pmx[i]]) {
                mx = twos[q[qmx[i]]] + twos[p[i - qmx[i]]];
            } else {
                mx = twos[p[pmx[i]]] + twos[q[i - pmx[i]]];
            }
        }
        cout << mx % 998244353 << ' ';
    }
    cout << '\n';
}

int main() {
    // Precalculate 2^x
    twos[0] = 1;
    for (int i = 1; i < 100000; ++i) {
        twos[i] = twos[i - 1] << 1;
        twos[i] %= 998244353;
    }

    int N;
    cin >> N;
    while (N--)
        run();
}

/*



*/