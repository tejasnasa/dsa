class Solution {
public:
    vector<pair<int,int>> dirs = {
        {0,-1}, {0,1}, {1,0}, {-1, 0}
    };

    const int inf = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i,j});
            }
        }

        int level = 0;

        while (!q.empty()) {
            int l = q.size();
            level++;

            while (l--) {
                auto coord = q.front();
                q.pop();
                for (auto &d: dirs) {
                    int x = coord.first + d.first;
                    int y = coord.second + d.second;

                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == inf) {
                        grid[x][y] = level;
                        q.push({x,y});
                    }
                }
            }
        }
    }
};
