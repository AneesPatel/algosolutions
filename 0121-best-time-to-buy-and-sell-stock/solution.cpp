class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, l = 0, r = l + 1;
        while (r < prices.size()){
            int curProfit = prices[r] - prices[l];
            if (profit < curProfit){
                profit = curProfit;
            }
            if (prices[r] < prices[l]){
                l = r;
            }
            r++;

        }
        return profit;

    }
};
