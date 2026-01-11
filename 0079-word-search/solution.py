class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rowmax, colmax = len(board), len(board[0])
        def backtrack(r, c, amountright):
            if amountright == len(word):
                return True
            if r < 0 or c < 0 or r >= rowmax or c >= colmax or board[r][c] != word[amountright]:
                return False
            
            temp = board[r][c]
            board[r][c] = "#"
            found = (backtrack(r, c - 1, amountright + 1) or 
                    backtrack(r, c + 1, amountright + 1) or 
                    backtrack(r + 1, c, amountright + 1) or 
                    backtrack(r - 1, c, amountright + 1))
            board[r][c] = temp
            return found

        
        for r in range(rowmax):
            for c in range(colmax):
                if board[r][c] == word[0] and backtrack(r, c, 0):
                    return True
        return False
