class Solution(object):
    def productExceptSelf(self, nums):
        otp = [1] * len(nums)
        pretest = 1
        for x in range(len(nums)):
            otp[x] = pretest
            pretest *= nums[x]
        posttest = 1
        for y in range(len(nums) -1, -1, -1):
            otp[y] *= posttest
            posttest *= nums[y]
        return otp


