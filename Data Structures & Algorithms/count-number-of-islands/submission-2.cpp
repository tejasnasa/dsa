class Solution {
public:
    void bfs(int i, int j, vector<vector<char>> &grid, int m, int n) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> coords = {
            {0,-1}, {0,1}, {-1,0}, {1,0}
        };

        grid[i][j] = '2';
        q.push({i,j});

        while (!q.empty()){
            auto [xc,yc] = q.front();
            q.pop();

            for (auto coord: coords) {
                int xval = xc + coord.first;
                int yval = yc + coord.second;

                if (xval >= 0 && yval >= 0 && xval < m && yval < n && grid[xval][yval] != '2' && grid[xval][yval] != '0') {
                    q.push({xval,yval});
                    grid[xval][yval] = '2';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(i,j,grid,m,n);
                    res++;
                }
            }
        }

        return res;
    }
};
