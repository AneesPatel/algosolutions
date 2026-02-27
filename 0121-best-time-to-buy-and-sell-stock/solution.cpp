class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int l = 0;
        int r = l + 1;
        int curprofit;
        while(r < prices.size()){
            curprofit = prices[r] - prices[l];
            if(maxprofit < curprofit){
                maxprofit = curprofit;
            }

            if(prices[r] < prices[l]){
                    l = r;
            }
            r++;
        }

        return maxprofit;
    }
};
