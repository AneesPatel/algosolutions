class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        freq = [[] for i in range(len(nums) + 1)]
        for n in nums:
            count[n] = 1 + count.get(n, 0)
        for n, c in count.items():
            freq[c].append(n)
        
        res2 = []
        for i in range(len(freq) -1, 0, -1):
            for n in freq[i]:
                res2.append(n)
                if len(res2) == k:
                    return res2
