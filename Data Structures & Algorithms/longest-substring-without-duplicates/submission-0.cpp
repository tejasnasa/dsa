class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();

        int l = 0, r = 0, res = 0;
        unordered_set<char> seen;

        while (r < s.length()) {
            cout << l << r << endl;
            
            while (seen.find(s[r]) != seen.end())  {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            
            res = max(res, r-l+1);
            r++;
        }

        return res;
    }
};
