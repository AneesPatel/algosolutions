class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        @cache
        def climb(index):
            if index >= len(cost):
                return 0
            return cost[index] + min(climb(index + 1), climb(index + 2))
        return min(climb(1), climb(0))
