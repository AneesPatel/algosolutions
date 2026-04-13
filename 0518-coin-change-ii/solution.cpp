class Solution {
public:
    int dp(int index, int amount, int target, vector<vector<int>>& memo, vector<int>& coins){
        if(target == amount){
            return 1;
        }
        if (index >= coins.size() or amount > target){
            return 0;
        }
        if(memo[index][amount] != -1){
            return memo[index][amount];
        }
        int temp = 0;
        temp += dp(index, amount + coins[index], target, memo, coins);
        temp += dp(index + 1, amount, target, memo, coins);
        memo[index][amount] = temp;
        return memo[index][amount];

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size() + 1, vector<int>(amount+ 1, -1));
        return dp(0, 0, amount, memo, coins);
    }
};
