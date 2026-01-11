class TrieNode:
    def __init__(self):
        self.children = {}
        self.isDone = False
        self.word = None
class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def add(self, word):
        cur = self.root
        for x in word:
            if x not in cur.children:
                cur.children[x] = TrieNode()
            cur = cur.children[x]
        cur.isDone = True
        cur.word = word


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        res = []
        trie = Trie()
        
        # 1. Build the Trie
        for word in words:
            trie.add(word) # FIX: Call add on the instance 'trie'

        # 2. Define the DFS Helper (The Core Logic)
        def dfs(r, c, node):
            # TODO: Base Case 1 - Bounds Check
            # If r or c is out of bounds (less than 0 or >= len), return.
            if r < 0 or r >= len(board) or c < 0 or c >= len(board[0]):
                return
            
            # TODO: Base Case 2 - Visited Check
            # If board[r][c] is '#', it means we are already using this cell in the current path. Return.
            
            char = board[r][c]
            if char == '#':
                return 
            # TODO: Base Case 3 - Trie Path Check
            # If 'char' is NOT in 'node.children', we can't form a word here. Return.
            if char not in node.children:
                return
            # --- If we pass the checks, we are on a valid path ---
            
            # Move our Trie pointer forward
            next_node = node.children[char]
            
            # Check if we found a word
            if next_node.isDone:
                res.append(next_node.word)
                next_node.isDone = False
                # OPTIONAL: Set next_node.isDone = False to avoid adding the same word twice
            
            # Mark current cell as visited
            board[r][c] = '#' 
            
            # TODO: Recursive Step
            # Call dfs(..., ..., next_node) for all 4 directions:
            # (r+1, c), (r-1, c), (r, c+1), (r, c-1)
            dfs(r+1,c, next_node)
            dfs(r-1,c, next_node)
            dfs(r,c+1, next_node)
            dfs(r,c-1, next_node)
            # Backtrack: Restore the cell letter so other searches can use it
            board[r][c] = char

        # 3. Iterate over every cell to trigger the search
        for r in range(len(board)):
            for c in range(len(board[0])):
                # Optimization: Only start DFS if the cell contains a letter that starts a word
                if board[r][c] in trie.root.children:
                    dfs(r, c, trie.root)
                    
        return res
