class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>> lis;
        
        for (int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(),t.end());
            lis.push_back({t, strs[i]});
        }

        sort(lis.begin(), lis.end());

        vector<vector<string>> res;

        string t = lis[0].first;
        res.push_back({lis[0].second});
        int x = 0;

        for (int i = 1; i < strs.size(); i++) {
            cout << lis[i].first << " " << lis[i].second << endl;
            if (lis[i].first == t) {
                res[x].push_back(lis[i].second);
            } else {
                x++;
                t = lis[i].first;
                res.push_back({lis[i].second});
            }
        }

        return res;
    }
};