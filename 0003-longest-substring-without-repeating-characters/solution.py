class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        templist = []
        for x in s:
            if x in templist:
                dup_index = templist.index(x)
                templist = templist[dup_index + 1:]
            templist.append(x)

            longest = max(longest, len(templist))
        return longest
