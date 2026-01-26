class Solution:
    def numDecodings(self, s: str) -> int:
        @cache
        def decode(index):
            if index == len(s):
                return 1
            if s[index] == '0':
                return 0
            res = decode(index + 1)
            if index + 1 < len(s) and int(s[index:index+2]) <= 26:
                res += decode(index + 2)
            return res
        return decode(0)
