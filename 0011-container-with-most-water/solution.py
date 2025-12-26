class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxheight = 0
        l = 0
        r = len(height) - 1
        while l < r:
            currheight = min(height[l], height[r]) * (r - l)
            maxheight = max(currheight, maxheight)
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return maxheight
