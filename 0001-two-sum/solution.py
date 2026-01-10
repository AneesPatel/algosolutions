class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        count = {}
        for i, x in enumerate(nums):
            if target - x in count:
                return [i, count[target-x]]
            else:
                count[x] = i

        return -1
