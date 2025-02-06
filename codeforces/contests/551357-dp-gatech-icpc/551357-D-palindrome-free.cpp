#include <iostream>
#include <string>
using namespace std;

string last = "";
int ind = -1;

bool check_palindrome_free(string n) {
    if (last != "") { // Check
        bool found = true;
        for (int i = 0; i < last.size(); ++i) {
            if (n[ind + i] != last[i]) {
                found = false;
                break;
            }
        }
        if (found) return true;
    }

    // Find Palindrome 2
    for (int i = 0; i < n.size() - 1; i++) {
        if (n[i] == n[i + 1]) {
            last = n.substr(i, 2);
            // n[i] + n[i + 1];
            ind = i;
            return true;
        }
    }

    // Find Palindrome 3
    for (int i = 1; i < n.size() - 1; i++) {
        if (n[i - 1] == n[i + 1]) {
            last = n.substr(i - 1, 3);
            // n[i - 1] + n[i] + n[i + 1];
            ind = i - 1;
            return true;
        }
    }
    return false;
}

int main() {
    long long A, B;
    cin >> A >> B;

    int total = 0;
    for (long long I = A; I <= B; ++I) {
        if (!check_palindrome_free(to_string(I))) // Not Palindrome
            ++total;
        else {
            // cout << "From: " << I << '\n';
            string n = to_string(I);
            if (last.size() + ind == n.size()) continue;
            for (int i = last.size(); i < n.size(); ++i)
                n[i] = '0';

            I = stoi(n) + pow(10, n.size() - last.size() - ind);
            // cout << "To: " << I << '\n';
        }
    }
    
    cout << total << '\n';
}