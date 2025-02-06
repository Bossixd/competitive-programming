#include <iostream>
using namespace std;

// int N;
// int num[101];
// int mx;
// int dp[101][1001];

// int helper(int i, int mx) {
//     if (dp[i][mx] > -1) return dp[i][mx];
//     if (i >= N) return mx;
    
//     dp[i][mx] = max(helper(i + 2, max(mx, num[i])) + 1, helper(i + 1, mx));
//     return dp[i][mx];
// }

// void test_case(int t) {
//     cin >> N;
    
//     for (int i = 0; i < N; ++i) 
//         cin >> num[i];
    
//     for (int i = 0; i < 101; ++i) 
//         for (int j = 0; j < 1001; ++j)
//             dp[i][j] = -1;

//     mx = 0;

//     int score = helper(0, 0);
//     cout << score << '\n';
// }

void test_case(int t) {
    int N;
    cin >> N;
    
    int c = 0;

    int cnt[2] = {0, 0};
    int mx[2] = {0, 0};

    for (int n = 0; n < N; ++n) {
        int b;
        cin >> b;
        cnt[c]++;
        mx[c] = max(mx[c], b);
        if (c == 0) c = 1;
        else c = 0;
    }

    cout << max(cnt[0] + mx[0], cnt[1] + mx[1]) << '\n'; 
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case(t);
}