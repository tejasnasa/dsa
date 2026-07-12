class Solution {
public:
    int dfs(int x, int y, int p, vector<vector<int>> &grid, int m, int n) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0) return 1;

        if (grid[x][y] == 2) return 0;
        
        grid[x][y] = 2;

        return dfs(x+1,y,p,grid,m,n) + 
        dfs(x-1,y,p,grid,m,n) +
        dfs(x,y+1,p,grid,m,n) +
        dfs(x,y-1,p,grid,m,n);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i,j,p,grid,m,n);
                }
            }
        }

        return 0;
        
    }
};