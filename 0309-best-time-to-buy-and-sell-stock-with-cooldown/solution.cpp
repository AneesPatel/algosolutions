class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<pair<int, int>> dp(n + 2, {0, 0});
        dp[0] = {-prices[0], 0};
        //dp[maxbuy, maxsell]
        for(int i = 1; i < n; ++i){
            int buyProfit = 0 - prices[i];
            if(i - 2 >= 0){
                buyProfit = dp[i - 2].second - prices[i];
            }
            int buyContinue = dp[i - 1].first;
            dp[i].first = max(buyProfit, buyContinue);
            
            int sellProfit = dp[i - 1].first + prices[i];
            int sellContinue = dp[i - 1].second;
            
            dp[i].second = max(sellProfit, sellContinue);
        }
        return dp[n - 1].second;
    }
};
