class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = collections.defaultdict(list)

        for x, v, w in times:
            edges[x].append((v, w))
        heap = [(0, k)]
        visited = set()
        res = 0
        while heap:
            weight, val = heapq.heappop(heap)
            if val in visited:
                continue
            res = max(res, weight)
            visited.add(val)
            for val1, weight1 in edges[val]:
                if val1 not in visited:
                    heapq.heappush(heap, (weight1 + weight, val1))

        
        if len(visited) == n:
            return res
        return -1
