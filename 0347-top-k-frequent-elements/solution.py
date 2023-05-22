class Solution(object):
    def topKFrequent(self, nums, k):
        numset = {}
        for x in nums:
            if not x in numset:
                numset[x] = nums.count(x)
        sortedset = []
        sorted_hmap = sorted(numset.items(), key=lambda x:x[1], reverse=True)
        for i in range(k):
            sortedset.append(sorted_hmap[i][0])
        return sortedset
            
