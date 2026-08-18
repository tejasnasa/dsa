class Solution {
public:
    vector<vector<int>> res;

    void perm(vector<int> &nums, vector<int> &subset, vector<bool> &used) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;

            subset.push_back(nums[i]);
            perm(nums, subset, used);
            subset.pop_back();

            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<bool> used(nums.size());

        perm(nums, subset, used);

        return res;
    }
};
