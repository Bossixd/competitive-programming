#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    int c1[26], c2[26], c3[26];

    pair<char, char> cards[3000];
    bool chosen_cards[3000];
    int mx_cards = 0;

    for (int i = 0; i < 26; ++i) {
        c1[i] = 0;
        c2[i] = 0;
        c3[i] = 0;
    }

    cin >> s1 >> s2 >> s3;

    for (auto c : s1)
        s1[c - 'a']++;

    for (auto c : s2)
        s2[c - 'a']++;

    for (auto c : s3)
        s3[c - 'a']++;
    
    for (int i = 0; i < 26; ++i) {
        int mx = 0;
        mx = max(mx, c1[i]);
        mx = max(mx, c2[i]);
        mx = max(mx, c3[i]);

        if (mx == 0) continue;


    }
}