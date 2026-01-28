class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        @cache
        def find(r, c):
            if r == m - 1 and c == n - 1:
                return 1
            if r >= m or c >= n:
                return 0
            return find(r + 1, c) + find(r, c + 1)
        return find(0, 0)
