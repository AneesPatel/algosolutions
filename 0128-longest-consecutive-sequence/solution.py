class Solution(object):
    def longestConsecutive(self, nums):
        sortednums = set(nums)
        longestseq = 0
        for x in nums:
            if not x - 1 in sortednums:
                count = 0
                while x + count in sortednums:
                    count += 1
                longestseq = max(longestseq, count)
        return longestseq
            

            
    
