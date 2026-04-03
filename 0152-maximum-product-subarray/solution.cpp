class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxVal = nums[0];
        int minVal = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            auto cur = nums[i];
            if(cur == 0){
                maxVal = 1;
                minVal = 1;
                res = max(res, cur);
                continue;
            }
            int temp = maxVal;
            maxVal = max(maxVal * cur, minVal * cur);
            maxVal = max(maxVal, cur);
            minVal = min(temp * cur, minVal * cur);
            minVal = min(minVal, cur);
            res = max(res, maxVal);
        }
        return res;
    }
};
