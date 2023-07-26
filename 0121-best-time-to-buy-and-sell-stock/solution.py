class Solution(object):
    def maxProfit(self, prices):
        profit = 0
        lowest = prices[0]
        for x in prices:
            if x < lowest:
                lowest = x
            profit = max(profit, x - lowest)
        return profit


