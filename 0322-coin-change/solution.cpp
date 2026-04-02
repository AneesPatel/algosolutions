class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int a = 1; a < amount + 1; ++a){
            for(auto coin : coins){
                if(a - coin >= 0){
                    dp[a] = min(dp[a], dp[a - coin] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX - 1){
            return -1;
        }

        return dp[amount];
    }
};
