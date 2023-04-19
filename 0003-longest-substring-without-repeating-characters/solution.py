class Solution(object):
    def lengthOfLongestSubstring(self, s):
        cset = set()
        p1 = 0
        longest = 0
        for p2 in range(len(s)):
            while s[p2] in cset:
                cset.remove(s[p1])
                p1 += 1 
            cset.add(s[p2])
            longest = max(longest, p2 - p1 + 1)
        return longest


            
