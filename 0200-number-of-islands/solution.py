class Solution:
    from collections import deque
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0
        res = 0
        rowlen, collen = len(grid), len(grid[0])
        directions = [(0,1), (0,-1), (1, 0), (-1, 0)]
        def bfs(r1, c1):
            
            q = deque()
            q.append((r1, c1))
            if grid[r1][c1] == '1': 
                grid[r1][c1] = '0'
            while q:
                r, c = q.popleft()
                for dr, dc in directions:
                    nr, nc = dr + r, dc + c
                    if nr < 0 or nc < 0 or nr >= rowlen or nc >= collen:
                        continue
                    if grid[nr][nc] == '1':
                        grid[nr][nc] = '0'
                        q.append((nr, nc))


        
        for r1 in range(rowlen):
            for c1 in range(collen):
                if grid[r1][c1] == '1':
                    res += 1
                    bfs(r1, c1)
        return res


