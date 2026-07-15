class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };
        int fresh = 0;
        int time = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 1) fresh++;
                if (grid[x][y] == 2) {
                    q.push({x,y});
                }
            }
        }

        while (!q.empty() && fresh != 0) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                auto front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;

                for (auto d: dir) {
                    int xd = x + d.first;
                    int yd = y + d.second;

                    if (xd >= 0 && yd >= 0 && xd < m && yd < n && grid[xd][yd] == 1) {
                        grid[xd][yd] = 2;
                        fresh--;
                        q.push({xd,yd});
                    }
                }
            }

            time++;
        }

        return fresh ? -1 : time;
    }
};
