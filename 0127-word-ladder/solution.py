class Solution:
    from collections import deque
    from collections import defaultdict

    def build_graph(self, beginWord, wordList):
        combo_dict = defaultdict(list)

        if beginWord not in wordList:
            wordList.append(beginWord)

        L = len(beginWord)

        for word in wordList:
            for i in range(L):
                new_pattern = word[:i] + "*" + word[i+1:]

                combo_dict[new_pattern].append(word)
                
        return combo_dict
    


    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
        # FIX 1: Use 'self.' and correct variable name 'wordList'
        graph = self.build_graph(beginWord, wordList)
        
        def bfs(starting_node, graph):
            queue = deque([(starting_node, 1)])
            visited = set([starting_node])

            while queue:
                curr_word, level = queue.popleft()
                
                if curr_word == endWord:
                    return level
                
                for i in range(len(curr_word)):
                    pattern = curr_word[:i] + "*" + curr_word[i+1:]
                    for neighbor in graph[pattern]:
                        if neighbor not in visited:
                            visited.add(neighbor)
                            queue.append((neighbor, level + 1))
            
            # FIX 2: If loop finishes without returning, return 0
            return 0 

        # FIX 3: Actually execute the BFS function!
        return bfs(beginWord, graph)
