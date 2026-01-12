class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [-x for x in stones]
        heapq.heapify(heap)
        while len(heap) > 1:
            x = heapq.heappop(heap)
            y = heapq.heappop(heap)
            if x == y:
                continue
            else:
                val = -1 * abs(x - y)
                heapq.heappush(heap, val)
        if not heap:
            return 0
        else:
            return heap[0] * -1
