#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int x = 0, y = 0, z = 0;
    int xb, yb, zb;
    for (int n = 0; n < N; ++n) {
        cin >> xb >> yb >> zb;
        x += xb;
        y += yb;
        z += zb;
    }

    if (x == 0 && y == 0 && z == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
        
    return 0;
}