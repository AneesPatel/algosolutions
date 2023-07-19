class Solution(object):
    def maxProfit(self, prices):
        low = prices[0]
        profit = 0
        for x in prices:
            if x < low:
                low = x
            profit = max(profit, x - low)
        return profit

