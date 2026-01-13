class Solution:
    from collections import defaultdict
    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0
        rowlen, collen = len(grid), len(grid[0])
        
        def dfs(r, c):
            if r >= rowlen or c >= collen or r < 0 or c < 0 or grid[r][c] == '0':
                return
            if grid[r][c] == '1':
                grid[r][c] = '0'
                dfs(r + 1, c)
                dfs(r - 1, c)
                dfs(r, c + 1)
                dfs(r, c - 1) 



        for row in range(rowlen):
            for col in range(collen):
                if grid[row][col] == '1':
                    res += 1
                    dfs(row, col)
        return res
