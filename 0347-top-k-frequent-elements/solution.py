class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        heap = []
        res = []
        for x in count:
            heap.append((count[x] * -1, (x)))
        heapq.heapify(heap)
        while len(res) < k:
            val = heapq.heappop(heap)
            res.append(val[1])
        return res
