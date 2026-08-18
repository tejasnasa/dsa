class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &nums, vector<int> &subset, int target, int i) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (target < 0 || i >= nums.size()) return;

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) continue;

            subset.push_back(nums[j]);
            dfs(nums, subset, target-nums[j], j+1);

            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, subset, target, 0);

        return res;
    }
};
