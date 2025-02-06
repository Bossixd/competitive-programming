#include <iostream>
#include <array>
using namespace std;

bool distinct(int num) {
    array<bool, 10> n;
    for (int i = 0; i < 10; ++i) n[i] = false;
    while (num > 0) {
        int digit = num % 10;
        num /= 10;
        if (!n[digit]) n[digit] = true;
        else return false;
    }
    return true;
}

int main() {
    int year;
    cin >> year;

    while (!distinct(++year));
    cout << year << '\n';
}