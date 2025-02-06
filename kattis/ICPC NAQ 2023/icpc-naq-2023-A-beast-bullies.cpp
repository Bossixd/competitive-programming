#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int n = 0; n < N; ++n) {
        cout << endl;
    }
}

/*
3
4
8
9

4 persp
if I push 3 out, 9 and 8 will join me because then one will die

4
8
9

8 persp
if I push 4 out, 9 + 4 will defend, and I will lose, so no

9 persp
if I push 4 out, 8 + 4 will defend, and I will lose, so no
*/