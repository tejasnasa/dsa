class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;

        for (auto n: nums) {
            count[n]++;
        }

        vector<pair<int,int>> values;

        for (auto val: count) {
            values.push_back({val.second, val.first});
        }

        sort(values.begin(), values.end());
        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(values[values.size()-i-1].second);
        }

        return res;
    }
};
