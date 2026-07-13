class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int hsh[1001] = {0};
        vector<int> res;

        for (int n: nums1) {
            hsh[n] = 1;
        }

        for (int n: nums2) {
            if (hsh[n] == 1) {
                hsh[n] = 0;
                res.push_back(n);
            }
        }

        return res;
    }
};