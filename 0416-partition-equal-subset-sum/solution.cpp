class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(total % 2 == 1){
            return false;
        }
        int need = total / 2;
        vector<bool> dp(need + 1, 0);
        //dp of i in total to whether or not it can be formed;
        dp[0] = true;
        // so lets iterate backwards
        for(auto cur : nums){
            for(int i = need; i >= cur; --i){
                
                dp[i] = dp[i] or dp[i-cur];
                
                
            }
        }
        return dp[need];
    }
};
