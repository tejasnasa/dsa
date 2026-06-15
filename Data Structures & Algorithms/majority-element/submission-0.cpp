class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        int max = -1;
        int res = -1;
        for (auto it: m) {
            cout << it.first << " " << it.second << endl;
            if (max < it.second) {
                max = it.second;
                res = it.first;
            }
        }

        return res;
    }
};