class Solution(object):
    def maxArea(self, height):
        p1, p2 = 0, len(height) - 1
        omax = 0
        while p1 < p2:
            cmax = min(height[p1], height[p2]) * (p2 - p1)
            if cmax > omax:
                omax = cmax
            if height[p1] > height[p2]:
                p2 -= 1
            else:
                p1 += 1
        return omax
