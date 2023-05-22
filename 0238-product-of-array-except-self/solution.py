class Solution(object):
    def productExceptSelf(self, nums):
        numset = [1] * len(nums) 
        pretest = 1
        for x in range(len(nums)):
            numset[x] = pretest
            pretest *= nums[x]

        posttest = 1
        for y in range(len(nums) - 1, -1, -1):
            numset[y] *= posttest
            posttest *= nums[y]
        return numset
