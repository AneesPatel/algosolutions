class Solution(object):
    def containsDuplicate(self, nums):
        seen = []
        for x in nums:
            if x in seen:
                return True
            else:
                seen.append(x)
        return False
