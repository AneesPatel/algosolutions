class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rowlen, collen = len(heights), len(heights[0])
        pac = set()
        atl = set()
        def dfs(r, c, prevvalue, visited):
            if (r, c) in visited:
                return
            if r < 0 or c < 0 or r >= rowlen or c >= collen or heights[r][c] < prevvalue:
                return
            visited.add((r, c))
            dfs(r + 1, c, heights[r][c], visited)
            dfs(r - 1, c, heights[r][c], visited)
            dfs(r, c - 1, heights[r][c], visited)
            dfs(r, c + 1, heights[r][c], visited)
            return

        for r in range(rowlen):
            dfs(r, 0, 0, pac)
            dfs(r, collen - 1, 0, atl)
    
        for c in range(collen):
            dfs(0, c, 0, pac)
            dfs(rowlen - 1, c, 0, atl)

        res = []
        for r in range(rowlen):
            for c in range(collen):
                if (r, c) in pac and (r,c) in atl:
                    res.append([r, c])
        return res

        
            

