class Solution {
public:
    void dfs(int og, int x, int y, vector<vector<int>> &image, int c) {
        if (x < 0 || y < 0 || x >= image.size() || y >= image[0].size() || image[x][y] != og) {
            return;
        }

        image[x][y] = c;

        dfs(og,x,y-1,image,c);
        dfs(og,x,y+1,image,c);
        dfs(og,x-1,y,image,c);
        dfs(og,x+1,y,image,c);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og = image[sr][sc];
        if (og == color) return image;
        
        dfs(og,sr,sc,image,color);

        return image;
    }
};