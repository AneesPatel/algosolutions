class Solution(object):
    def isAnagram(self, s, t):
        if sorted(t) == sorted(s):
            return True
        return False
        
