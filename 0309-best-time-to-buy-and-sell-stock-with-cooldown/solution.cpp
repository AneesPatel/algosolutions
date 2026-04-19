class Solution {
public:
    int dp(int i, int state, vector<int>& prices, vector<vector<int>>& memo){
        if(i >= prices.size()) return 0;
        if(memo[i][state] != -1) return memo[i][state];

        // Option 1: Skip today (stay in same state)
        int res = dp(i + 1, state, prices, memo);

        // Option 2: Act today
        if(state == 0){ // Buying state
            res = max(res, dp(i + 1, 1, prices, memo) - prices[i]);
        } else { // Selling state
            res = max(res, dp(i + 2, 0, prices, memo) + prices[i]);
        }

        return memo[i][state] = res;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        // Use 2 states: 0 = looking to buy, 1 = looking to sell
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dp(0, 0, prices, memo);
    }
};

