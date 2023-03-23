class Solution(object):
    def twoSum(self, nums, target):
        prev = {}
        for i, x in enumerate(nums):
            diff = target - x
            if diff in prev:
                return(prev[diff], i)
            prev[x] = nums.index(x)
        return()
        
