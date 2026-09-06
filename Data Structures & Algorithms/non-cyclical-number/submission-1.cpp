class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;

        while(true) {
            int sum = 0;

            while (n > 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }

            cout << sum << endl;

            if (sum == 1) return true;
            else if (m.contains(sum)) return false;
            else {
                m[sum]++;
                n = sum;
            }
        }

        return false;
    }
};
