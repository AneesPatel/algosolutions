class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        @cache
        def find(r, c):
            if r == len(grid) - 1 and c == len(grid[0]) - 1:
                return grid[r][c]
            if r >= len(grid) or c >= len(grid[0]):
                return float('inf')
            return grid[r][c] + min(find(r + 1, c), find(r, c + 1))
        return find(0, 0)
