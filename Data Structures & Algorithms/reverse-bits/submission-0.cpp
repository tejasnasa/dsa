class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = "";
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                s += '1';
            } else s += '0';
        }

        uint32_t res = 0;
        reverse(s.begin(), s.end());

        for (int i = 0; i < 32; i++) {
            if (s[i] == '1') {
                res |= (1 << i);
            }
        }

        return res;
    }
};
