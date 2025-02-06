#include <iostream>
using namespace std;

int main() {
    #define int long long int

    int N;
    cin >> N;

    int mxl = 0;
    int S, E;
    int mni, mxi;
    int mn = 1000000001, mx = 0;
    int index = 0;
    for (int n = 0; n < N; ++n) {
        cin >> S >> E;
        if (E - S + 1> mxl) {
            mni = S;
            mxi = E;
            index = n;
            mxl = E - S;
        }
        mn = min(mn, S);
        mx = max(mx, E);
    }

    if (mn < mni || mx > mxi) cout << -1;
    else cout << index + 1;
    cout << '\n';

    return 0;
}