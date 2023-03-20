class Solution(object):
    def topKFrequent(self, nums, k):
        hmap = {}
        for x in nums:
            if not x in hmap:
                hmap[x] = nums.count(x)
        otp = []
        sorted_hmap = sorted(hmap.items(), key=lambda x:x[1], reverse=True)
        print(sorted_hmap)
        #converted_hmap = dict(sorted_hmap)
        #print(converted_hmap)
        for i in range(k):
            otp.append(sorted_hmap[i][0])
        return (otp)
