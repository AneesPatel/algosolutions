class Solution(object):
    def productExceptSelf(self, nums):
        final = [1] * len(nums)
        pretest = 1
        for x in range(len(nums)):
            final[x] = pretest
            pretest *= nums[x]
        posttest = 1
        for y in range(len(nums) - 1, -1, -1):
            final[y] *= posttest
            posttest *= nums[y]
        return final



