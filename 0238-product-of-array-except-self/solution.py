class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = 1
        postfix = 1
        res = [1] * len(nums)
        for x in range(len(nums)):
            res[x] *= prefix
            prefix *= nums[x]
            
        for x in range(len(nums) - 1, -1, -1):
            res[x] *= postfix
            postfix *= nums[x]

        return res
