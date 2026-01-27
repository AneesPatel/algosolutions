class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[len(s)] = True
        for index in range(len(s) - 1, -1, -1):
            for curWord in wordDict:
                if len(s) >= (len(curWord) + index) and s[index:index+len(curWord)] == curWord:
                    dp[index] = dp[len(curWord) + index]
                if dp[index]:
                    break
        return dp[0]
