#include <iostream>

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = i;

    std::cout << arr[-1] << '\n';
}