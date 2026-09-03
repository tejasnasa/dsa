#include <cstring>

class Solution {
public:
    int dp[205][205];

    int dfs(vector<vector<int>> &grid, int i, int j) {
        // cout << grid[i][j] << endl;
        int m = grid.size();
        int n = grid[0].size();

        if (i == m-1 && j == n-1) return dp[i][j] = grid[i][j];
        if (i == m || j == n) return dp[i][j] = INT_MAX;

        if (dp[i][j] != -1) return dp[i][j];

        int down = dfs(grid, i+1, j);
        int right = dfs(grid, i, j+1);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));

        return dfs(grid, 0, 0);
    }
};