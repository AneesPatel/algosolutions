class Solution(object):
    def longestConsecutive(self, nums):
      longest = 0
      numsset = set(nums)
      for x in nums:
        if not x - 1 in numsset:
          count = 0
          while x + count in numsset:
            count += 1
          longest = max(count, longest)
      return longest

    
