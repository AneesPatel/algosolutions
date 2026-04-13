class Solution {
public:
    int total;
    int goal;
    int dp(int index, int amount, vector<vector<int>>& memo, vector<int>& nums){
        if(index == nums.size()){
            if(amount == goal + total){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(memo[index][amount] != -1){
            return memo[index][amount];
        }
        int temp = 0;
        temp += dp(index + 1, amount + nums[index], memo, nums);
        temp += dp(index + 1, amount - nums[index], memo, nums);
        memo[index][amount] = temp;
        return memo[index][amount];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        total = 0;
        goal = target;
        for(auto cur : nums){
            total += cur;
        }
        //[11111], -5 -> 5;
        vector<vector<int>> memo(nums.size() + 1, vector<int>((total * 2) + 1, -1));
        //memo[index][amount] = amount of paths able to makke it to target;
        return dp(0, total, memo, nums);
    }
};
