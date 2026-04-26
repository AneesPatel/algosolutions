class Solution:
    from bisect import bisect_left
    def maxAlternatingSum(self, nums: list[int], k: int) -> int:
        s = sorted(set(nums))
        m = len(s)
        n = len(nums)
        f_b, g_b, f, g = [0]*(m + 1), [0]*(m + 1), [0]*n, [0]*n
        def upd(t, i, v):
            while i <= m: t[i] = max(t[i], v); i += i & -i
        def qry(t, i, r = 0):
            while i > 0: r = max(r, t[i]); i -=i & -i
            return r
        res = -float('inf')
        for i, x in enumerate(nums):
            if i >= k:
                r = bisect_left(s, nums[i-k]) + 1
                upd(f_b, r, f[i-k])
                upd(g_b, m - r + 1, g[i - k])
            r = bisect_left(s, x) + 1
            g[i], f[i] = x + qry(f_b, r- 1), x + qry(g_b, m - r)
            res = max(res, f[i], g[i])
        return res
