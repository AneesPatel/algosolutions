class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        dic = {}
        res = []
        for i, x in enumerate(nums):
            l = i + 1
            r = len(nums) - 1
            if i > 0 and x == nums[i - 1]:
                continue
            while l < r:
                if nums[l] + nums[r] + x == 0:
                    res.append(sorted([nums[l], nums[r], x]))
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                elif nums[l] + nums[r] + x > 0:
                    r -= 1
                else:
                    l += 1
        return res
