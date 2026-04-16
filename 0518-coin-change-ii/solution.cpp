class Solution {
public:
    int dp(int index, int amount, vector<int>& coins, vector<vector<int>>& memo){
        if(amount == 0){
            return 1;
        }
        if(index >= coins.size() or amount < 0){
            return 0;
        }
        if(memo[amount][index] != -1){
            return memo[amount][index];
        }
        int temp = 0;
        temp += dp(index, amount - coins[index], coins, memo);
        temp += dp(index + 1, amount, coins, memo);
        memo[amount][index] = temp;
        return memo[amount][index];
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(amount + 1,vector<int>(coins.size() + 1, -1));
        //dp[value][index]
        return dp(0, amount, coins, memo);
    }
};
