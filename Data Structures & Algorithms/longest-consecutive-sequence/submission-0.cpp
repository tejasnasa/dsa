class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        int maxval = 0;

        for (int n: numSet) {
            if (numSet.find(n-1) == numSet.end()) {
                int length = 1;

                while (numSet.find(n+length) != numSet.end()) {
                    length++;
                }

                maxval = max(length,maxval);
            }
        }

        return maxval;
    }
};
