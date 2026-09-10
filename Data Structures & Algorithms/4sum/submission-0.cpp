class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            m[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i+1; j < n; j++) {
                m[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                for (int k = j+1; k < n; k++) {
                    m[nums[k]]--;
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;

                    long long fourth = target - (nums[i] + nums[j] + 0LL + nums[k]);
                    if (fourth < INT_MIN || fourth > INT_MAX) continue;
                    if (m[fourth] > 0) {
                        res.push_back({nums[i], nums[j], nums[k], int(fourth)});
                    }
                }

                for (int k = j+1; k < nums.size(); k++) {
                    m[nums[k]]++;
                }
            }

            for (int j = i+1; j < nums.size(); j++) {
                m[nums[j]]++;
            }
        }

        return res;
    }
};