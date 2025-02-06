#include <iostream>
using namespace std;

int rec() {

}

int test_case() {
    string s;
    cin >> s;
    cout << (rec() ? "YES" : "NO") << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--)
        test_case();
}