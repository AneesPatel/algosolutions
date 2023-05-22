class Solution(object):
    def containsDuplicate(self, nums):
        numset = set()
        for x in nums:
            if x in numset:
                return True
            else:
                numset.add(x)
        return False
