class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        xString = str(x)
        if xString == xString[::-1]:
            return True
        else:
            return False
         
        
