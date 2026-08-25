class Solution {
public:
    int reverse(int x) {
        vector<int> digits;
        bool neg = false;

        if (x < 0) {
            neg = true;
            x = abs(x);
        }

        while (x != 0) {
            digits.push_back(x % 10);
            cout << x%10;
            x /= 10;
        }

        std::reverse(digits.begin(), digits.end());

        long long lo = INT_MIN, hi = INT_MAX, res;

        for (int i = 0; i < digits.size(); i++) {
            res += digits[i]*pow(10, i);
        }

        if (neg) res = -res;

        return (lo <= res && res <= hi) ? (int)res : 0;
    }
};
