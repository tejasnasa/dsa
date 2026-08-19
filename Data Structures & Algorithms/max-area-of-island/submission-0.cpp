class Solution {
public:
    vector<pair<int,int>> dirs = {
        {0,-1}, {0,1}, {1, 0}, {-1, 0}
    };

    int dfs(vector<vector<int>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        int area = 0;

        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }

        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            area++;
        }
        
        for (auto &d: dirs) {
            area += dfs(grid, i+d.first, j+d.second);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }

        return res;
    }
};
