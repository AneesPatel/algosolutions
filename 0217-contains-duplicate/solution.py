class Solution(object):
    def containsDuplicate(self, nums):
        nums2 = set()
        for x in nums:
            if x in nums2:
                return True
            else:
                nums2.add(x)
        return False
