class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        premap = {i:[] for i in range(numCourses)}
        visited = set()
        for x in prerequisites:
            premap[x[0]].append(x[1])
        
        def dfs(cur):
            if cur in visited:
                return False
            if premap[cur] == []:
                return True
            visited.add(cur)
            for x in premap[cur]:
                if not dfs(x):
                    return False
            premap[cur] = []
            visited.remove(cur)
            return True 

        for x in range(numCourses):
            if not dfs(x):
                return False
        return True

