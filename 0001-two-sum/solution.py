class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        count = {}
        res = []
        for ind, val in enumerate(nums):
            if target - val in count:
                return [ind, count[target-val]]
            else:
                count[val] = ind
        return -1
