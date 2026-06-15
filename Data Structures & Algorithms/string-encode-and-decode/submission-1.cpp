class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for (auto s: strs) {
            int n = s.length();
            res += to_string(n) + "#" + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, n = s.size();

        while (i < n) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }

        return res;
    }
};
