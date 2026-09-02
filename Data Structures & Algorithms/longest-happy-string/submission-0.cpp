class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> heap;
        string s = "";

        if (a > 0) heap.push({a, 'a'});
        if (b > 0) heap.push({b, 'b'});
        if (c > 0) heap.push({c, 'c'});

        while (!heap.empty()) {
            auto x = heap.top();
            heap.pop();

            cout << x.first << x.second << endl;

            int n = s.length();

            if (n >= 2 && s[n-1] == x.second && s[n-2] == x.second) {
                if (heap.empty()) break;
                auto y = heap.top();
                heap.pop();

                s += y.second;
                if (y.first-1 > 0) heap.push({y.first-1, y.second});
                heap.push(x);
            } else {
                s += x.second;
                if (x.first-1 > 0) heap.push({x.first-1, x.second});
            } 
        }

        return s;
    }
};