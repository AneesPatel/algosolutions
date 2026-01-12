class MedianFinder:

    def __init__(self):
        self.minheap = []
        self.maxheap = []

    def addNum(self, num: int) -> None:
        heapq.heappush(self.minheap, num * -1)
        if self.minheap and self.maxheap:
            if (self.minheap[0] * -1) > (self.maxheap[0]):
                val = -1 * heapq.heappop(self.minheap)
                heapq.heappush(self.maxheap, val)
            elif (len(self.minheap) - len(self.maxheap)) > 1:
                val = -1 * heapq.heappop(self.minheap)
                heapq.heappush(self.maxheap, val)
        if (len(self.maxheap) - len(self.minheap)) > 1:
            val = -1 * heapq.heappop(self.maxheap)
            heapq.heappush(self.minheap, val)
        elif (len(self.minheap) - len(self.maxheap)) > 1:
            val = -1 * heapq.heappop(self.minheap)
            heapq.heappush(self.maxheap, val)

    def findMedian(self) -> float:
        if len(self.minheap) > len(self.maxheap):
            return self.minheap[0] * -1
        elif len(self.maxheap) > len(self.minheap):
            return self.maxheap[0]
        else:
            return ((self.minheap[0]  * -1) + self.maxheap[0])/2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
