class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        if (prices.size() == 2) return (prices[1]>prices[0] ? prices[1]-prices[0] : 0);

        int l = 0, r = 1, maxval=0;

        while (r <= prices.size()-1) {
            if (prices[l] > prices[r]) {
                l = r;
                r = l+1;
            } else if (prices[l] <= prices[r]) {
                maxval = max(maxval,prices[r]-prices[l]);
                r++;
            }
        }

        return maxval;
    }
};
