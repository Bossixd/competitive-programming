#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int T;
    cin >> T;

    cout << setprecision(9);

    for (int t = 0; t < T; ++t) {
        int N, P;
        cin >> N >> P;
        double X = (double) P * ((double) pow(100.0, 1.0 / N) * (double) pow(1.0 / P, 1.0 / N) - 1.0);
        cout << "Case #" << t + 1 << ": " << X << '\n';
    }
}