class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums, vector<int> &subset, int target, int i) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (target < 0 || i >= nums.size()) return;

        subset.push_back(nums[i]);
        dfs(nums, subset, target-nums[i], i);

        subset.pop_back();
        dfs(nums, subset, target, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;

        dfs(nums, subset, target, 0);

        return res;
    }
};
