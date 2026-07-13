class Solution {
public:
    int firstUniqChar(string s) {
        int hsh[26] = {0};

        for (auto c: s) {
            hsh[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (hsh[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};