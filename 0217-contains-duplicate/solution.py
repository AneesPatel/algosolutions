class Solution(object):
    def containsDuplicate(self, nums):
        numsset = set()
        for x in nums:
            if x in numsset:
                return True
            numsset.add(x)
        return False
