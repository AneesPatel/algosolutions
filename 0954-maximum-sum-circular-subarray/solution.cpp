class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res = nums[0];
        int curmax = nums[0];
        int total = accumulate(nums.begin(), nums.end(), 0);
        int curmin = nums[0];
        int resmin = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            curmax = max(nums[i], curmax + nums[i]);
            curmin = min(nums[i], curmin + nums[i]);
            resmin = min(resmin, curmin);
            res = max(curmax, res);

        }
        if(res < 0){
            return res;
        }
        return max(res, total - resmin);
    }
};
