#include <iostream>
#include <unordered_set>
using namespace std;

void test_case() {
    int N;
    cin >> N;

    if (N == 2 || N == 3 || N == 4)
        cout << "-1\n";

    if (N < 7) {
        if (N == 5)
            cout << "2 4 5 1 3\n";
        else if (N == 6)
            cout << "2 4 5 1 3 6\n";
    } else {
        for (int i = 4; i <= N; i += 2) {
            cout << i << ' ';
        }
        cout << "2 7 ";
        for (int i = (N % 2 == 0 ? N - 1 : N); i > 7; i -= 2)
            cout << i << ' ';
        cout << "5 3 1\n";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--)
        test_case();
}