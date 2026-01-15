class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:    
        @cache
        def maximum(bars):
            sorted_bars = sorted(bars)
            prev = -2
            best = 1
            curr = 1
            for x in sorted_bars:
                if x == prev + 1:
                    curr += 1
                else:
                    curr = 1
                best = max(best, curr)
                prev = x
            return best + 1

        return min(maximum(tuple(hBars)), maximum(tuple(vBars))) ** 2
