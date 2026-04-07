class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(total % 2 == 1){
            return false;
        }
        int target = total/2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto cur : nums){
            for(int i = target; i >= cur; --i){
                dp[i] = dp[i] or dp[i - cur];
            }
        }
        return dp[target];

        
    }
};
