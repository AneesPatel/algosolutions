class Solution:
    from collections import heapq
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        res = []
        heap = []
        for x in count:
            heapq.heappush(heap, (count[x] * -1, x))
        while len(res) < k:
            cur = heapq.heappop(heap)
            res.append(cur[1])
        return res

