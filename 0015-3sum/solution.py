class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        result = []
        for i, x in enumerate(nums):
            if i > 0 and nums[i - 1] == x:
                continue
            p1, p2 = i + 1, len(nums) - 1
            while p1 < p2:
                threesum = x + nums[p1] + nums[p2]
                if threesum < 0:
                    p1 += 1
                elif threesum > 0:
                    p2 -= 1
                else:
                    result.append([x, nums[p1], nums[p2]])
                    p1 += 1
                    while p1 < p2 and nums[p1] == nums[p1 - 1]:
                        p1 += 1
        return result


