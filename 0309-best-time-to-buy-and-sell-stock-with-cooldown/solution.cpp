class Solution {
public:
    int dp(int i, int j, vector<vector<int>>& memo, vector<int>& prices){
        if(j >= prices.size() or i >= prices.size()){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int cur_profit = prices[j] - prices[i];
        
        memo[i][j] = max(cur_profit + dp(j + 2, j + 3, memo, prices), dp(j, j + 1, memo, prices));
        memo[i][j] = max(memo[i][j], dp(i, j + 1, memo, prices));
        return memo[i][j];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][j] = max path profit;
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return dp(0, 1, memo, prices);

    }
};
