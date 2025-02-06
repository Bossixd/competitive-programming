#include <iostream>
using namespace std;

void test_case() {
    string s;
    cin >> s;
    string r;
    for (auto c : s) {
        int i = int(c - '0');
        if (i & (1 << 2)) r += 'r';
        else r += '-';

        if (i & (1 << 1)) r += 'w';
        else r += '-';

        if (i & 1) r += 'x';
        else r += '-';
    }
    cout << r << '\n';
    
}

int main() {
    int T;
    cin >> T;
    while (T--)
        test_case();
}

// 1 1
/*
0: 0 0 0
0: 0 0 1
0: 0 1 0 
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1 

*/