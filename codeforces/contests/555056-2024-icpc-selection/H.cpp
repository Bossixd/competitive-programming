#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

void test_case(int t);

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
        test_case(t);
}

void test_case(int t) {
    #define int long long int
    int a, b;
    int n, o, cnt;
    
    cin >> a >> b;
    n = min(a, b);
    o = max(a, b);

    priority_queue<int, vector<int>, std::greater<int> > pq;
    set<int> s;

    // Case 1 % ลงตัว
    // cout << "Case 1\n";
    for (int i = 1; i * i <= n + 1; i++) {
        bool pass = n % i == 0;
        if (!pass) continue;
        if ((o - 2) % i == 0 && s.find(i) == s.end()) {
            pq.push(i);
            s.insert(i);
        }
        int nxt = n / i;
        if ((o - 2) % nxt == 0 && s.find(nxt) == s.end()) {
            pq.push(nxt);
            s.insert(nxt);
        }
    }

    // Case 2 % -1 ลงตัว
    // cout << "Case 2\n";
    for (int i = 1; i * i <= n + 1; i++) {
        bool pass = (n - 1) % i == 0;
        if (!pass) continue;
        if ((o - 1) % i == 0 && s.find(i) == s.end()) {
            // cout << i << '\n';
            pq.push(i);
            s.insert(i);
        }
        if (o % i == 0 && (o - 2) % i == 0 && s.find(i) == s.end()) {
            // cout << i << '\n';
            pq.push(i);
            s.insert(i);
        }
        int nxt = (n - 1) / i;
        if ((o - 1) % nxt == 0 && s.find(nxt) == s.end()) {
            // cout << i << '\n';
            pq.push(nxt);
            s.insert(nxt);
        }

        if (o % nxt == 0 && (o - 2) % nxt == 0 && s.find(nxt) == s.end()) {
            pq.push(nxt);
            s.insert(nxt);
        }
    }

    // Case 3 % -2 ลงตัว
    // cout << "Case 3\n";
    for (int i = 1; i * i <= n + 1; i++) {
        bool pass = (n - 2) % i == 0;
        if (!pass) continue;
        if (o % i == 0 && s.find(i) == s.end()) {
            // cout << i << '\n';
            pq.push(i);
            s.insert(i);
        }
        int nxt = (n - 2) / i;
        if (o % nxt == 0 && s.find(nxt) == s.end()) {
            // cout << i << '\n';
            pq.push(nxt);
            s.insert(nxt);
        }
    }

    n = max(a, b);
    o = min(a, b);


    // Case 1 % ลงตัว
    // cout << "Case 1\n";
    for (int i = 1; i * i <= n + 1; i++) {
        bool pass = n % i == 0;
        if (!pass) continue;
        if ((o - 2) % i == 0 && s.find(i) == s.end()) {
            pq.push(i);
            s.insert(i);
        }
        int nxt = n / i;
        if ((o - 2) % nxt == 0 && s.find(nxt) == s.end()) {
            pq.push(nxt);
            s.insert(nxt);
        }
    }

    // Case 2 % -1 ลงตัว
    // cout << "Case 2\n";
    for (int i = 1; i * i <= n + 1; i++) {
        bool pass = (n - 1) % i == 0;
        if (!pass) continue;
        if ((o - 1) % i == 0 && s.find(i) == s.end()) {
            // cout << i << '\n';
            pq.push(i);
            s.insert(i);
        }
        if (o % i == 0 && (o - 2) % i == 0 && s.find(i) == s.end()) {
            // cout << i << '\n';
            pq.push(i);
            s.insert(i);
        }
        int nxt = (n - 1) / i;
        if ((o - 1) % nxt == 0 && s.find(nxt) == s.end()) {
            // cout << i << '\n';
            pq.push(nxt);
            s.insert(nxt);
        }

        if (o % nxt == 0 && (o - 2) % nxt == 0 && s.find(nxt) == s.end()) {
            pq.push(nxt);
            s.insert(nxt);
        }
    }

    // Case 3 % -2 ลงตัว
    // cout << "Case 3\n";
    for (int i = 1; i * i <= n + 1; i++) {
        bool pass = (n - 2) % i == 0;
        if (!pass) continue;
        if (o % i == 0 && s.find(i) == s.end()) {
            // cout << i << '\n';
            pq.push(i);
            s.insert(i);
        }
        int nxt = (n - 2) / i;
        if (o % nxt == 0 && s.find(nxt) == s.end()) {
            // cout << i << '\n';
            pq.push(nxt);
            s.insert(nxt);
        }
    }

    cout << s.size() << ' ';
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}
