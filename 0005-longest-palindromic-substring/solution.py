class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        start = 0
        end = 0
        
        # 1. Changed loop variable 'x' to 'i' to match usage below
        for i in range(len(s)):
            # 2. Added 'self.' to call the class method
            len1 = self.expand(s, i, i)
            len2 = self.expand(s, i, i + 1)
            max_len = max(len1, len2)
            
            # The 'end - start' here tracks the length of the currently found max string
            # (Note: standard solution usually tracks max_len separate from indices, 
            # but this works if we treat end as inclusive index)
            if max_len > end - start:
                # 3. Logic Fix: Integer division (// 2) is required to find the offset
                start = i - (max_len - 1) // 2
                end = i + max_len // 2
                
        return s[start:end+1]
    
    def expand(self, s: str, l: int, r: int):
        # 4. Fixed variable names: changed 'left'/'right' to 'l'/'r'
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return r - l - 1
