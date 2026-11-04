class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. sort all words, and map the common words (word -> array of words)
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());

            m[s].push_back(strs[i]);
        }

        for (auto &p: m) {
            res.push_back(p.second);
        }

        return res;
    }
};
