class Solution {
public:
    int dp(int l, int r, vector<int>& nums, vector<vector<int>>& memo){
        if(l > r){
            return 0;
        }
        if(memo[l][r] != -1){
            return memo[l][r];
        }
        int temp = 0;
        for(int i = l; i <= r; ++i){
            temp = max(temp, dp(l, i - 1, nums, memo) + (nums[l - 1] * nums[r + 1] * nums[i]) + dp(i + 1, r, nums, memo));
        }
        memo[l][r] = temp;
        return memo[l][r];
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> memo(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return dp(1, nums.size() - 2, nums, memo);
    }
};
