class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];
            if (m.find(val) != m.end()) {
                int x = m.find(val)->second;
                vector<int> v = {x,i};
                return v;
            } else {
                m.insert({nums[i],i});
            }
        }

        vector<int> d = {0};
        return d;
        
    }
};