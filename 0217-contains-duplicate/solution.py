class Solution(object):
    def containsDuplicate(self, nums):
        hashset = set()
        for x in nums:
            if x in hashset:
                return True
            else:
                hashset.add(x)
        return False
