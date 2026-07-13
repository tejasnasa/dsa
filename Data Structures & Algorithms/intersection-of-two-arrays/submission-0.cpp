class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int hsh[1001] = {0};
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        vector<int> res;

        for (int n: set1) {
            hsh[n]++;
        }

        for (int n: set2) {
            hsh[n]++;
        }

        for (int i = 0; i < 1001; i++) {
            if (hsh[i] == 2) {
                res.push_back(i);
            }
        }

        return res;
    }
};