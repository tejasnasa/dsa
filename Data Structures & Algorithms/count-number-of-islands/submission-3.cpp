class Solution {
public:
    vector<pair<int,int>> coords = {
        {-1,0}, {1,0}, {0,1}, {0,-1}
    };

    void dfs(int i, int j, vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        grid[i][j] = '0';

        for (int k = 0; k < 4; k++) {
            int x = i + coords[k].first;
            int y = j + coords[k].second;

            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1') {
                dfs(x,y,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i,j,grid);
                    res++;
                }
            }
        }

        return res;
    }
};
