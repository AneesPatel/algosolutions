class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        newLeft = newInterval[0]
        newRight = newInterval[1]
        for i, cur in enumerate(intervals):
            curLeft = cur[0]
            curRight = cur[1]
            if curLeft > newRight:
                res.append([newLeft, newRight])
                return res + intervals[i:]
            elif curRight < newLeft:
                res.append(cur)
            else:
                newLeft = min(newLeft, curLeft)
                newRight = max(newRight, curRight)
        res.append([newLeft, newRight])
        return res
