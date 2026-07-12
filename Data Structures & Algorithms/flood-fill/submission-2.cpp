class Solution {
public:
    void bfs(int og, int x, int y, vector<vector<int>> &image, int c) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> coords = {
            {0,-1}, {0,1}, {1,0}, {-1,0}
        };
        image[x][y] = c;
        q.push({x,y});

        while (!q.empty()) {
            pair<int,int> val = q.front();
            int xval = val.first;
            int yval = val.second;
            q.pop();

            for (auto coord: coords) {
                int xc = xval + coord.first;
                int yc = yval + coord.second;

                if (xc >= 0 && yc >= 0 && xc < image.size() && yc < image[0].size() && image[xc][yc] == og) {
                    image[xc][yc] = c;
                    q.push({xc, yc});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og = image[sr][sc];
        if (og == color) return image;
        
        bfs(og,sr,sc,image,color);

        return image;
    }
};