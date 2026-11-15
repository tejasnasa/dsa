class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;         

        while (l<=r) {
            int mid = (l+r) / 2;
            int x = mid / n;
            int y = mid % n;
            // cout << matrix[x][y];

            if (target < matrix[x][y]) r = mid - 1;
            else if (matrix[x][y] < target) l = mid + 1;
            else return true;
        }

        return false;
    }
};
