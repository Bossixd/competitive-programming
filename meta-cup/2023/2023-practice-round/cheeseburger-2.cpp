#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long mx = 0;
        
        long long ac = (long long) (c / a);
        if (ac < 0) ac = 0;
        long long al = c % a;

        long long bc = (long long) (c / b);
        if (bc < 0) bc = 0;
        long long bl = c % b;

        long long ab = (long long) (al / b);
        long long abuns = (ac + ab) * 2;
        long long ameat = ac + ab * 2;
        long long atotal = min(ameat, abuns - 1);
        if (atotal < 0) atotal = 0;

        long long bb = (long long) (bl / a);
        long long bbuns = (bb + bc) * 2;
        long long bmeat = bb + bc * 2;
        long long btotal = min(bmeat, bbuns - 1);
        if (btotal < 0) btotal = 0;

        mx = max(atotal, btotal);

        // if (c < a) {
        //     cout << "Case #" << i + 1 << ": " << mx << '\n';
        //     continue;
        // }

        // if (c >= a) {
        //     int cl = c - a;

        //     long long cb = (long long) (cl / b);
        //     long long cbuns = (1 + cb) * 2;
        //     long long cmeat = 1 + cb * 2;
        //     long long ctotal = min(cmeat, cbuns);
        //     if (ctotal < 0) ctotal = 0;
        //     mx = max(mx, ctotal);
        // }

        // if (c >= a * 2) {
        //     int cl = c - a * 2;

        //     long long cb = (long long) (cl / b);
        //     long long cbuns = (2 + cb) * 2;
        //     long long cmeat = 2 + cb * 2;
        //     long long ctotal = min(cmeat, cbuns);
        //     if (ctotal < 0) ctotal = 0;
        //     mx = max(mx, ctotal);
        // }

        cout << "Case #" << i + 1 << ": ";
        // cout << ac << ' ' << bc << '\n';
        // cout << ab << ' ' << bb << '\n';
        // cout << abuns << ' ' << bbuns << '\n';
        // cout << ameat << ' ' << bmeat << '\n';
        // cout << atotal << ' ' << btotal << '\n';
        cout << mx << '\n';
    }
    
    return 0;
}