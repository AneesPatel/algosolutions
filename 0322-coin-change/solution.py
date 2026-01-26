class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        @cache
        def coin(left):
            if left == 0:
                return 0
            if left <= 0:
                return float('inf')
            lowest = float('inf')
            for cur in coins:
                res = coin(left - cur)
                lowest = min(lowest, res + 1)
            return lowest
        res = coin(amount)
        if res == float('inf'):
            return -1
        return res
