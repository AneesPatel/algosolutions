class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        if n == 1:
            return 1
        if n == 0:
            return 0
        count = 0
        dp = [[False] * n for _ in range(n)]
        for x in range(n):
            dp[x][x] = True
            count += 1
        for length in range(2, n + 1):
            for l in range(n - length + 1):
                r = l + length - 1
                if s[l] == s[r]:
                    if length == 2 or dp[l + 1][r - 1]:
                        dp[l][r] = True
                        count += 1
        return count
