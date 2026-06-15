class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for (int i = 0; i < 9; i++) {
            int check[10] = {0};

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (check[board[i][j]-'0'] == 0) {
                    check[board[i][j]-'0'] += 1;
                }
                else return false;
            }
        }

        // row check
        for (int i = 0; i < 9; i++) {
            int check[10] = {0};

            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;

                if (check[board[j][i]-'0'] == 0) {
                    check[board[j][i]-'0'] += 1;
                }
                else return false;
            }
        }

        // diagonal check
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // cout << i*3 << j*3 << endl;
                int check[10] = {0};

                for (int k = i*3; k < i*3+3; k++) {
                    for (int l = j*3; l < j*3+3; l++) {
                        cout << k << l << " ";
                        if (board[k][l] == '.') continue;

                        if (check[board[k][l]-'0'] == 0) {
                            check[board[k][l]-'0'] += 1;
                        }
                        else return false;
                    }                        
                }
            }
        }

        return true;
    }
};
