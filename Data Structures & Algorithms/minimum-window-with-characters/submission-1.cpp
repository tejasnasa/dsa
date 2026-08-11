class Solution {
public:
    bool valid(unordered_map<char,int>& hsh, unordered_map<char,int>& need) {
        for (auto& [ch, cnt] : need) {
            if (hsh[ch] < cnt) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int l = 0, r = 0, minlen = INT_MAX, left = 0;
        
        unordered_map<char,int> hsh, need;
        for (char c : t) need[c]++;

        int required = need.size(), have = 0;

        while (r < s.length()) {
            hsh[s[r]]++;
            if (need.contains(s[r]) && hsh[s[r]] == need[s[r]]) {
                have++;
            }
            
            while(have == required) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    left = l;
                }
                if (need.contains(s[l]) && hsh[s[l]] == need[s[l]]) {
                    have--;
                }
                hsh[s[l]]--;
                l++;
            }
            
            r++;
        }

        return (minlen == INT_MAX) ? "" : s.substr(left,minlen);
    }
};
