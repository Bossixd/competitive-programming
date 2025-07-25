#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long dx = qx - px;
        long long dy = qy - py;
        long long d_sq = dx * dx + dy * dy;

        long long L = 0, R = 0;
        for (long long x : a) {
            if (x >= R) {
                L = x - R;
            } else if (x <= L) {
                L = L - x;
            } else {
                L = 0;
            }
            R += x;
        }

        if (d_sq <= R * R && d_sq >= L * L) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}