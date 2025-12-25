class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for x in nums:
            count[x] = count.get(x, 0) + 1
        freq = [[] for i in range(len(nums) + 1)]
        for n, f in count.items():
            freq[f].append(n)
        res = []

        for x in range(len(freq) - 1, 0, -1):
            for y in freq[x]:
                res.append(y)
                if (len(res) == k):
                    return res
