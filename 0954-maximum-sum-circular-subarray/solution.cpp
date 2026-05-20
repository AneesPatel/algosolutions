class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int trueMax = nums[0];
        int curMax = nums[0];
        int trueMin = nums[0];
        int curMin = nums[0];
        int total = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 1; i < nums.size(); ++i){
            curMax = max(curMax + nums[i], nums[i]);
            curMin = min(curMin + nums[i], nums[i]);
            trueMax = max(curMax, trueMax);
            trueMin = min(curMin, trueMin);
        }
        if(trueMax < 0){
            return trueMax;
        }
        return max(trueMax, total - trueMin);
    }
};
