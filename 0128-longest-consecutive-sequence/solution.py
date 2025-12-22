class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        longest = 0
        nums_set = set(nums)

        for x in nums_set:
            if x - 1 not in nums_set:
                length = 1
                while x + length in nums_set:
                    length += 1
                longest = max(longest, length)

        return longest
