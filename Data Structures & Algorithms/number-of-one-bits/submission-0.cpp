class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int x = 1;
        for (int i = 0; i < 32; i++) {
            if (n & (x << i)) res++;
        }

        return res;
    }
};
