class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        premap = {i:[] for i in range(numCourses)}
        visited = set()
        cycle = set()
        for x in prerequisites:
            premap[x[0]].append(x[1])
        res = []
        def dfs(cur):
            if cur in cycle:
                return False
            if cur in visited:
                return True
            cycle.add(cur)
            for x in premap[cur]:
                if not dfs(x):
                    return False
            cycle.remove(cur)
            visited.add(cur)
            res.append(cur)
            return True
        for cur in range(numCourses):
            if not dfs(cur):
                return []
        return res
