#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define int long long

template <typename T, typename U>
pair<T, U> mkp(const T& first, const U& second) {
    return make_pair(first, second);
}

void solve() {
    int n;
    cin >> n;

    double sx = 0, sy = 0;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
        sx += v[i][0];
        sy += v[i][1];
    }

    sx /= (double) n;
    sy /= (double) n;

    int ssx = round(sx);
    int ssy = round(sy);

    vector<pair<int, pair<int, int>>> q1, q2, q3, q4;
    vector<pair<int, pair<int, int>>> xt, yt, xb, yb, o;

    for (int i = 0; i < n; ++i) {
        if (v[i][0] > ssx) {
            if (v[i][1] > ssy)
                q1.push_back(mkp(i, mkp(v[i][0], v[i][1])));
            else if (v[i][1] < ssy)
                q4.push_back(mkp(i, mkp(v[i][0], v[i][1])));
            else
                yt.push_back(mkp(i, mkp(v[i][0], v[i][1])));
        } else if (v[i][0] < ssx) {
            if (v[i][1] > ssy)
                q2.push_back(mkp(i, mkp(v[i][0], v[i][1])));
            else if (v[i][1] < ssy)
                q3.push_back(mkp(i, mkp(v[i][0], v[i][1])));
            else
                yb.push_back(mkp(i, mkp(v[i][0], v[i][1])));
        } else {
            if (v[i][1] == ssy)
                o.push_back(mkp(i, mkp(v[i][0], v[i][1])));
            else if (v[i][1] > ssy)
                xt.push_back(mkp(i, mkp(v[i][0], v[i][1])));
            else
                xb.push_back(mkp(i, mkp(v[i][0], v[i][1])));
        }
    }
    
    cout << ssx << ' ' << ssy << "\n\n";

    cout << "q1\n";
    for (auto i : q1)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    cout << "q2\n";
    for (auto i : q2)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    cout << "q3\n";
    for (auto i : q3)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    cout << "q4\n";
    for (auto i : q4)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    cout << "xt\n";
    for (auto i : xt)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    cout << "xb\n";
    for (auto i : xb)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    cout << "yt\n";
    for (auto i : yt)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    cout << "yb\n";
    for (auto i : yb)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    cout << "o\n";
    for (auto i : o)
        cout << i.first << " : " << i.second.first << ' ' << i.second.second << '\n';
    cout << '\n';

    int cnt = 0;

    int oi = 0, xti = 0, xbi = 0, yti = 0, ybi = 0;

    // for (int i = 0; i < min(xt.size(), xb.size()); ++i) {
    //     cnt += (abs(xt[xti].second.first - xb[xbi].second.first) + abs(xt[xti].second.second - xb[xbi].second.second));
    //     cout << xt[xti++].first << ' ' << xb[xbi++].first << '\n';
    // }

    // for (int i = 0; i < min(yt.size(), yb.size()); ++i) {
    //     cnt += (abs(yt[yti].second.first - yb[ybi].second.first) + abs(yt[yti].second.second - yb[ybi].second.second));
    //     cout << yt[yti++].first << ' ' << yb[ybi++].first << '\n';
    // }

    int i = 0;

    if (q1.size() > q3.size())
        for (auto i1 : q1) {
            pair<int, pair<int, int>> i3;
            if (i < q3.size())
                i3 = q3[i++];
            else if (ybi < yb.size())
                i3 = yb[ybi++];
            else if (xbi < xb.size())
                i3 = xb[xbi++];
            else
                i1 = o[oi++];
            
            cout << i1.first << ' ' << i3.first << '\n';
            cnt += (abs(i1.second.first - i3.second.first) + abs(i1.second.second - i3.second.second));
        }
    else
        for (auto i3 : q3) {
            pair<int, pair<int, int>> i1;
            if (i < q1.size())
                i1 = q1[i++];
            else if (yti < yt.size())
                i1 = yt[yti++];
            else if (xti < xt.size())
                i3 = xt[xti++];
            else
                i1 = o[oi++];
            
            cout << i1.first << ' ' << i3.first << '\n';
            cnt += (abs(i1.second.first - i3.second.first) + abs(i1.second.second - i3.second.second));
        }
    
    i = 0;
    if (q2.size() > q4.size())
        for (auto i2 : q2) {
            pair<int, pair<int, int>> i4;
            if (i < q4.size())
                i4 = q4[i++];
            else if (ybi < yb.size())
                i4 = yb[ybi++];
            else if (xbi < xb.size())
                i4 = xb[xbi++];
            else
                i4 = o[oi++];
            
            cout << i2.first << ' ' << i4.first << '\n';
            cnt += (abs(i2.second.first - i4.second.first) + abs(i2.second.second - i4.second.second));
        }
    else
        for (auto i3 : q3) {
            pair<int, pair<int, int>> i1;
            if (i < q1.size())
                i1 = q1[i++];
            else if (yti < yt.size())
                i1 = yt[yti++];
            else if (xti < xt.size())
                i1 = xt[xti++];
            else
                i1 = o[oi++];
            
            cout << i1.first << ' ' << i3.first << '\n';
            cnt += (abs(i1.second.first - i3.second.first) + abs(i1.second.second - i3.second.second));
        }
        

    cout << cnt << '\n';
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
