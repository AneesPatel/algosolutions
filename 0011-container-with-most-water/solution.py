class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0 
        r = len(height) - 1
        res = 0
        while l < r:
            waterval = min(height[l], height[r]) * (r - l)
            res = max(res, waterval)
            if height[r] < height[l]:
                r -= 1
            else:
                l += 1
        return res
