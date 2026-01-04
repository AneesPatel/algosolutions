class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i, x in enumerate(nums):
            if x > 0:
                break
            if i > 0 and x == nums[i - 1]:
                continue
            l = i + 1
            r = len(nums) - 1

            while l < r:
                tempres = []
                if nums[l] + nums[r] + x == 0:
                    tempres = [nums[l], nums[r], x]
                    res.append(tempres)
                    l += 1
                    r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                elif nums[l] + nums[r] + x < 0:
                    l += 1
                else:
                    r -= 1

        return res




