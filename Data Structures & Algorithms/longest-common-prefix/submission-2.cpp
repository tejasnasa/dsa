class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 0;
        int flag = 1;
        if (strs.size() == 1) return strs[0];
        for (int j = 0; j < 201; j++) {
            int c = strs[0][j];

            for (int i = 1; i < strs.size(); i++) {
                if (c != strs[i][j]) {
                    len = j;
                    flag = 0;
                }
            }
            if (flag == 0) break;
        }
        
        return strs[0].substr(0,len);
    }
};