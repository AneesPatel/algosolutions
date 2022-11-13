class Solution(object):
    def containsDuplicate(self, nums):
        numsset = set()
        for x in nums:
            if x in numsset:
                return True
            else:
                numsset.add(x)
        return False
