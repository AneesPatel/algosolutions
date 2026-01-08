class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return "" # Fix: Return empty string, not False
            
        count, window = {}, Counter(t)
        res, resLen = [-1, -1], float("inf")
        l = 0
        have, need = 0, len(window)
        
        for r in range(len(s)):
            c = s[r]
            count[c] = 1 + count.get(c, 0)

            if c in window and count[c] == window[c]:
                have += 1
            
            while have == need:
                # update our result
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = (r - l + 1)
                
                # pop from the left of our window
                # TODO 3: Decrement count[s[l]] (not remove)
                count[s[l]] -= 1 
                
                # TODO 4: If s[l] in window and count[s[l]] < window[s[l]], decrement 'have'
                if s[l] in window and count[s[l]] < window[s[l]]:
                    have -= 1
                l += 1
                
        l, r = res
        return s[l : r+1] if resLen != float("inf") else ""
