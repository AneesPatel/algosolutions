class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        prev = set()
        for x in nums:
            if x in prev:
                return True
            else:
                prev.add(x)
        return False
