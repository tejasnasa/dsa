class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
 
        vector<int> leftMax(height.size(), 0), rightMax(height.size(), 0);

        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(height[i-1], leftMax[i-1]);
        }

        for (int i = height.size()-2; i >= 0; i--) {
            rightMax[i] = max(height[i+1], rightMax[i+1]);
        }

        int res = 0;

        for (int i = 0; i < height.size(); i++) {
            int area = min(leftMax[i],rightMax[i]) - height[i];
            
            if (area >= 1) res += area;
        }

        return res;
    }
};
