class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int hsh[3] = {0};

        for (int i = 0; i < bills.size(); i++) {
            cout << hsh[0] << " " << hsh[1] << endl;
            if (bills[i] == 5) {
                hsh[0]++;
            } else if (bills[i] == 10) {
                if (hsh[0]) {
                    hsh[0]--;
                    hsh[1]++;
                } else return false;
            } else {
                if (hsh[0] && hsh[1]) {
                    hsh[0]--;
                    hsh[1]--;
                    hsh[2]++;
                } else if (hsh[0] >= 3) {
                    hsh[0] -= 3;
                    hsh[2]++;
                } else return false;
            }
        }

        return true;
    }
};