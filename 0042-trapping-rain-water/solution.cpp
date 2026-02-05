class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        int maxLeft = height[l], maxRight = height[r];

        while (l < r){
            if (maxLeft > maxRight){
                r--;
                int cur = maxRight - height[r];
                if(cur > 0){
                    res += cur;
                }
                if (height[r] > maxRight){
                    maxRight = height[r];
                }
            }
            else{
                l++;
                int cur = maxLeft - height[l];
                if(cur > 0){
                    res += cur;
                }
                if (height[l] > maxLeft){
                    maxLeft = height[l];
                }
            }
        }
        return res;
    }
};
