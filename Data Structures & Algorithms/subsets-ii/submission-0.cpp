class Solution {
public:
    vector<vector<int>> res;

    void sub(vector<int> &nums, vector<int> &subset, int i) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        if (i > nums.size()) return;

        subset.push_back(nums[i]);
        sub(nums, subset, i+1);

        subset.pop_back();
        while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        sub(nums, subset, i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());

        sub(nums, subset, 0);

        return res;
    }
};
