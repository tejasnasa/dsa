class Solution {
public:
    vector<pair<int,int>> coords = {
        {0,-1}, {0,1}, {1,0}, {-1,0}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        // 1 1 2
        // 1 0 0
        // 1 2 0
        queue<pair<int,int>> q;
        int minutes = 0;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i,j});
            }
        }

        while (fresh > 0 && !q.empty()) {
            minutes++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto rotten = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = rotten.first + coords[i].first;
                    int y = rotten.second + coords[i].second;

                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
