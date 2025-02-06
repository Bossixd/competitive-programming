#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
    for (int i = 2; i <= n / 2; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int N;
    cin >> N;

    /*/
    for (int i = N + 1, l = i + N; i < l; ++i)
        cout << i << ' ';
    cout << '\n';
    /*/

    /**/
    int n = 0, i = 2;
    while (n < N) {
        if (prime(i++)) {
            n++;
            cout << i - 1 << ' ';
        }
    }
    cout << '\n';
    /**/

    return 0;
}