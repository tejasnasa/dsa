class Solution {
public:
    vector<string> children(string &s) {
        vector<string> res;

        for (int i = 0; i < 4; i++) {
            string t = s;
            t[i] = (s[i] - '0' + 1) % 10 + '0';
            res.push_back(t);

            t = s;
            t[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(t);
        }

        return res;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());

        if (visit.contains("0000")) return -1;

        queue<pair<string,int>> q;
        q.push({"0000", 0});
        visit.insert("0000");

        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            if (x.first == target) return x.second;

            for (string child: children(x.first)) {
                if (!visit.contains(child)) {
                    visit.insert(child);
                    q.push({child, x.second + 1});
                }
            }
        }

        return -1;
    }
};