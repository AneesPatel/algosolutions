class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMax = nums[0];
        int curMax = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            curMax = max(nums[i], curMax + nums[i]);
            globalMax = max(curMax, globalMax);
        }
        return globalMax;
    }
};
