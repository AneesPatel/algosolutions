class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevs = {}
        for i in range(len(nums)):
            goal = target - nums[i]
            if goal in prevs:
                return [i, prevs[goal]]
            else:
                prevs[nums[i]] = i
        return -1
