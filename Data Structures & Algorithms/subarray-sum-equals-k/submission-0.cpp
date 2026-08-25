class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pf;
        int res = 0, sum = 0;
        pf[0]++;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += pf[sum-k];
            pf[sum]++;
        }

        return res;
    }
};