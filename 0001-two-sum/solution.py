class Solution(object):
    def twoSum(self, nums, target):
        prevs = {}
        for i, x in enumerate(nums):
            diff = target - x
            if diff in prevs:
                return(i, prevs[diff])
            prevs[x] = i
