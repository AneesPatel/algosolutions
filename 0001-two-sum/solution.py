class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = {}
        for i, x in enumerate(nums):
            if target - x in res:
                return[i, res[target-x]]
            else:
                res[x] = i
            
        return -1

