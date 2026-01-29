class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        count = 0
        for cur in nums:
            count += cur
            if count > res:
                res = count
            if count < 0:
                count = 0
        return res
