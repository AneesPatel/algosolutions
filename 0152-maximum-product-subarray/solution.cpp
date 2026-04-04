class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minval = nums[0];
        int maxval = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == 0){
                res = max(res, nums[i]);
                minval = 1;
                maxval = 1;
                continue;
            }
            int cur = nums[i];
            int temp = maxval;
            maxval = max(maxval * cur, minval * cur);
            maxval = max(maxval, cur);

            minval = min(temp * cur, minval * cur);
            minval = min(minval, cur);
            res = max(res, maxval);
        }
        return res;
    }
};
