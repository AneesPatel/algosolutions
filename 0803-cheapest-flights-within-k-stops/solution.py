class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        edges = collections.defaultdict(list)
        for x, v, w in flights:
            edges[x].append((v, w))
        heap = [(0, src, 0)]
        visited = [float('inf')] * n
        while heap:
            weight, val, count = heapq.heappop(heap)
            if count > k + 1:
                continue
            if count >= visited[val]:
                continue
            if val == dst:
                return weight
            visited[val] = count
            for val1, weight1 in edges[val]:
                heapq.heappush(heap, (weight1 + weight, val1, count + 1))
        return -1
                                
