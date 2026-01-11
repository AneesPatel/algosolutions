class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrace(path):
            if len(nums) == len(path):
                res.append(path[:])
                return
            
            for x in nums:
                if x in path:
                    continue
                path.append(x)
                backtrace(path)
                path.pop()
        backtrace([])
        return res
