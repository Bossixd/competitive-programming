#include <iostream>
using namespace std;

long long int A;
int B;

// int dp[1000000000000000001];

int rec(long long int N, short int last, int d3) {
    if (N == 3) {
        
    }
    int total = 0;
    for (int i = 1; i <= 9 && i != last; ++i)
        total = (total + rec(A - 1, i, (d3 + i) % 9)) % 1000000007;
    return total % 1000000007;
}

int main() {
    cin >> A >> B;

    return rec(A, -1, 0);
}

/*
It’s your Venusian friend’s birthday. You don’t remember their exact age, but you are sure it had
to be no more than 10^18 years. 
You will give them a decimal number (without leading zeros) for their birthday. 

**You want the number of digits to be equal to their age**

**To make the number more interesting you will ensure that no adjacent pairs of digits will be identical.**

Their exact day of birth is represented as an integer in the range 0 to 224 (since Venus has 225 days in a year). 

**To make their gift more personal you want the given number to have the same remainder as their birthday when divided by 225.**

There are potentially a lot of possible gifts that you could give. You may decide to give more than
one gift. Determine the number of possible gifts modulo 109 + 7.
*/