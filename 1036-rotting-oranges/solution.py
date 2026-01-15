class Solution:
    from collections import deque
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid: return -1
        res = 0
        freshcount = 0
        rowlen, collen = len(grid), len(grid[0])
        q = deque()
        directions = ((0, 1), (0, -1), (-1, 0), (1, 0))
        for row in range(rowlen):
            for col in range(collen):
                if grid[row][col] == 2:
                    q.append((row, col))
                if grid[row][col] == 1:
                    freshcount += 1
        if freshcount == 0:
            return 0
        while q:
            res += 1
            for _ in range(len(q)):
                r, c = q.popleft()
                for r1, c1 in directions:
                    nr, nc = r1 + r, c1 + c
                    if nr < 0 or nc < 0 or nr >= rowlen or nc >= collen:
                        continue
                    if grid[nr][nc] == 1:
                        freshcount -= 1
                        grid[nr][nc] = 2
                        q.append((nr, nc))
            if freshcount == 0:
                return res
        if freshcount > 0:
            return -1
        return res

