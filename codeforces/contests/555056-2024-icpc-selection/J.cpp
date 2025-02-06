#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int grid[129][129];
int comp[129][129];
int chosen_col[129];
int chosen_row[129];

unordered_map<int, unordered_map<int, int> > dp;

int rec(int row, int col_mask) {
    if (row == N + 1) return 0;
    int mx = 0;

    if (dp[row].find(col_mask) != dp[row].end())
        return dp[row][col_mask];

    for (int i = 1; i <= N; ++i) { 
        // If col has been chosen, continue
        if (col_mask & (1 << i)) continue;

        // Choosing col i in row row

        // Check if valid
        bool valid = true;
        for (int j = 1; j <= N && col_mask & (1 << j); ++j) {

            int crow = chosen_row[j];
            int ccol = chosen_col[j];

            int nrow = row;
            int ncol = i;

            if (!(((grid[crow][ncol] < grid[crow][ccol] && comp[crow][ncol] < comp[nrow][ncol]) || 
                (grid[crow][ncol] > grid[crow][ccol] && comp[crow][ncol] > comp[nrow][ncol])) &&
                ((grid[nrow][ccol] < grid[crow][ccol] && comp[nrow][ccol] < comp[nrow][ncol]) || 
                (grid[nrow][ccol] > grid[crow][ccol] && comp[nrow][ccol] > comp[nrow][ncol])))) {
                    valid = false;
                    break;
                }
        }

        if (!valid) continue;

        chosen_row[i] = row;
        chosen_col[i] = i;

        col_mask = col_mask | (1 << i);

        mx = max(mx, comp[row][i] + rec(i + 1, col_mask));

        col_mask = col_mask & ~(1 << i);

        chosen_row[i] = -1;
        chosen_col[i] = -1;
    }
    
    dp[row][col_mask] = mx;
    return dp[row][col_mask];
}

int main()
{
    cin >> N;

    int b;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> comp[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        chosen_col[i] = -1;
        chosen_row[i] = -1;
    }

    cout << rec(1, 0) << '\n';
}