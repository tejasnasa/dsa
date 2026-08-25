class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasS = 0, costS = 0;
        for (int i = 0; i < gas.size(); i++) {
            gasS += gas[i];
            costS += cost[i];
        }

        if (costS > gasS) return -1;

        int res = 0, use = 0;

        for (int i = 0; i < gas.size(); i++) {
            use += gas[i] - cost[i];

            if (use < 0) {
                res = i+1;
                use = 0;
            }
        }

        return res;
    }
};
