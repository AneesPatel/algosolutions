class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        def backtrack(index, path, remaining):
            if remaining == 0:
                res.append(path[:])
            for x in range(index, len(candidates)):
                val = candidates[x]
                if val > remaining:
                    continue
                path.append(val)
                backtrack(x, path, remaining - val)
                path.pop()
        backtrack(0, [], target)
        return res
