class Solution {
public:
    int rowSearch(int l, int r, vector<vector<int>>& matrix, int len, int target) {
        if (l>r) return -1;
        int mid = l + (r-l)/2;

        if (target < matrix[mid][0]) {
            return rowSearch(l,mid-1,matrix,len,target);
        } else if (target > matrix[mid][len]) {
            return rowSearch(mid+1,r,matrix,len,target);
        } else {
            return mid;
        }
    }

    bool search(int l, int r, vector<int> &row, int target) {
        if (l > r) return false;
        int mid = l + (r-l)/2;

        if (target < row[mid]) {
            return search(l,mid-1,row,target);
        } else if (target > row[mid]) {
            return search(mid+1,r,row,target);
        } else {
            return true;
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();

        int row = rowSearch(0,m-1,matrix,n-1,target);
        if (row == -1) return false;

        return search(0,n-1,matrix[row],target);
    }
};
