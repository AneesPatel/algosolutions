class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        rowlen, collen = len(image), len(image[0])
        def dfs(r, c, prevcolor):
            if r < 0 or c < 0 or r >= rowlen or c >= collen:
                return
            if image[r][c] == color:
                return
            if image[r][c] == prevcolor:
                image[r][c] = color
                dfs(r, c - 1, prevcolor)
                dfs(r, c + 1, prevcolor)
                dfs(r - 1, c, prevcolor)
                dfs(r + 1, c, prevcolor)
        dfs(sr, sc, image[sr][sc])
        return image
