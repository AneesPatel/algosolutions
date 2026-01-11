class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        def backtrack(index, path):
            if path not in res:
                res.append(path[:])

            for x in range(index, len(nums)):
                path.append(nums[x])
                backtrack(x + 1, path)
                path.pop()
    
        backtrack(0, [])  
        return res

            
