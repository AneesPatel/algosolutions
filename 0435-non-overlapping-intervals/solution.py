class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals: return 0
        intervals.sort(key=lambda i:i[0])
        res = 0
        prevRight = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] < prevRight:
                res += 1
                prevRight = min(prevRight, intervals[i][1])
            else:
                prevRight = intervals[i][1]
        return res
