class Solution {
public:
    vector<pair<int,int>> dirs = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    bool dfs(vector<vector<char>> &board, const string &word, int i, int j, int k) {
        if (board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;

        int m = board.size(), n = board[0].size();
        char temp = board[i][j];
        board[i][j] = '#';

        bool result = false;
        for (auto &p : dirs) {
            int x = i + p.first, y = j + p.second;
            if (x >= 0 && y >= 0 && x < m && y < n) {
                if (dfs(board, word, x, y, k+1)) {
                    result = true;
                    break;
                }
            }
        }

        board[i][j] = temp; // backtrack
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};
