class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.size() == 1) return strs[0];
        
        sort(strs.begin(), strs.end());
        string x = strs[0];
        string y = strs[strs.size()-1];

        string prefix;

        for (int i = 0; i < x.length(); i++) {
            if (x[i] == y[i]) {
                prefix += x[i];
            } else break;
        }
         
         return prefix;
       
    }
};