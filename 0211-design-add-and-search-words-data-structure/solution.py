class TrieNode:

    def __init__(self):
        self.children = {}
        self.isWordDone = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        cur = self.root
        for x in word:
            if x not in cur.children:
                cur.children[x] = TrieNode()
            cur = cur.children[x]
        cur.isWordDone = True

    def search(self, word: str) -> bool:
        def dfs(index, root):
            cur = root
            for i in range(index, len(word)):

                char = word[i]
                if char == '.':
                    for y in cur.children.values():
                        if dfs(i + 1, y):
                            return True
                    return False
                else: 
                    if char not in cur.children:
                        return False
                    cur = cur.children[char]
            return cur.isWordDone
        return dfs(0, self.root)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
