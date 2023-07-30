class Solution(object):
    def twoSum(self, nums, target):
        hashmap = {}
        for i, x in enumerate(nums):
            if target - x in hashmap:
                return(hashmap[target - x], i)
            hashmap[x] = i
        return
            

