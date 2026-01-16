class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        def bfs(index, path, remaining):
            if remaining == 0:
                res.append(path[:])
            for cur in range(index, len(candidates)):
                if candidates[cur] > remaining:
                    continue
                path.append(candidates[cur])
                bfs(cur, path, remaining - candidates[cur])
                path.pop()
        bfs(0, [], target)
        return res
