class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length()-1;
        vector<int> visited(n+1, -1);
        if (s[n] == '1') return false;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int len = q.size();

            while(len--) {
                int x = q.front();
                
                q.pop();

                for (int i = minJump; i <= maxJump; i++) {
                    if (x+i == n) {
                        return true;
                    } else if (x+i > n) break;

                    if (s[x+i] == '0' && visited[x+i] == -1) {
                        visited[x+i] = 0;
                        q.push(x+i);
                    }
                }
            }
        }

        return false;
    }
};