class Solution(object):
    def maxProfit(self, prices):
        lowest = prices[0]
        profit = 0
        for x in prices:
            if lowest > x:
                lowest = x
            profit = max(profit, x - lowest)

        return profit
