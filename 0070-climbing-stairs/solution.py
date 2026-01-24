class Solution:
    def climbStairs(self, n: int) -> int:
        @cache
        def climb(cur):
            if cur > n:
                return 0
            if cur == n:
                return 1
            return climb(cur + 1) + climb(cur + 2)
        return climb(0)
