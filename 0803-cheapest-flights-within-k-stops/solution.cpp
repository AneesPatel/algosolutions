class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n + 1, INT_MAX);
        prices[src] = 0;
        for(int i = 0; i < k + 1; ++i){
            vector<int> tempPrices = prices;
            for(const auto& cur : flights){
                int from = cur[0];
                int to = cur[1];
                int price = cur[2];
                if(prices[from] == INT_MAX){
                    continue;
                }
                if(prices[from] + price < tempPrices[to]){
                    tempPrices[to] = prices[from] + price;
                }
            }
            swap(prices, tempPrices);
        }
        if(prices[dst] == INT_MAX){
            return -1;
        }
        return prices[dst];
    }
};
