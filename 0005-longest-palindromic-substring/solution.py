class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n <= 1:
            return s
        dp = [[False] * n for _ in range(n)]
        longest = ""
        for x in range(n):
            dp[x][x] = True
            longest = s[0]
        for length in range(2, n + 1):
            for l in range(n - length + 1):
                r = l + length - 1
                if s[l] == s[r]:
                    if length == 2 or dp[l + 1][r - 1]:
                        dp[l][r] = True
                        if length > len(longest):
                            longest = s[l:r + 1]
        return longest
