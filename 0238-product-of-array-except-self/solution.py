class Solution(object):
    def productExceptSelf(self, nums):
        res = [1] * len(nums)
        
        pretest = 1
        for x in range(len(nums)):
            res[x] = pretest
            pretest *= nums[x]
        posttest = 1
        for y in range(len(nums) - 1, -1, -1):
            res[y] *= posttest
            posttest *= nums[y]
        return res
