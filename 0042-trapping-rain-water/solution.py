class Solution(object):
    def trap(self, height):
        if not height:
            return 0
        p2, p1 = len(height) - 1, 0
        total = 0
        p1max, p2max = height[p1], height[p2]
        while p1 < p2:
            if p2max > p1max:
                p1 += 1
                p1max = max(p1max, height[p1])
                total += p1max - height[p1]
            else:
                p2 -= 1
                p2max = max(p2max, height[p2])
                total += p2max - height[p2]
        return total
            
            

           
           

