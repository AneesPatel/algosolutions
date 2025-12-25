class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for x, val in enumerate(nums):
            l = x + 1
            r = len(nums) - 1
            if val > 0:
                break
            if x > 0 and val == nums[x-1]:
                continue
            while l < r:
                threeSum = val + nums[l] + nums[r]
                
                if threeSum > 0:
                    r -= 1
                elif threeSum < 0:
                    l += 1
                else:
                    res.append([val, nums[l], nums[r]])
                    l += 1
                    r -= 1
                    
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
        return res


                

