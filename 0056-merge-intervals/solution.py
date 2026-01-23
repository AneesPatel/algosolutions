class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        res = []
        intervals.sort(key=lambda x: x[0])
        prevLow = intervals[0][0]
        prevHigh = intervals[0][1]
        for curLow, curHigh in intervals:
            if curLow > prevHigh:
                res.append([prevLow, prevHigh])
                prevHigh = curHigh
                prevLow = curLow
            else:
                prevHigh = max(prevHigh, curHigh)
        res.append([prevLow, prevHigh])
        return res
