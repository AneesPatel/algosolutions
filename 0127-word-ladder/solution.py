class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList: return 0
        pattern = collections.defaultdict(list)

        for word in wordList:
            for index in range(len(word)):
                tpattern = word[:index] + '*' + word[index + 1:]
                pattern[tpattern].append(word)
        
        q = deque([beginWord])
        visited = set()
        visited.add(beginWord)
        res = 1
        while q:
            for _ in range(len(q)):
                curword = q.popleft()
                if curword == endWord:
                    return res
                for index in range(len(curword)):
                    tpattern = curword[:index] + '*' + curword[index + 1:]
                    for samepat in pattern[tpattern]:
                        if samepat not in visited:
                            visited.add(samepat)
                            q.append(samepat)
            res += 1
        
        return 0
