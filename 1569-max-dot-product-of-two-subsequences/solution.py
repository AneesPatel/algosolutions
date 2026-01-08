from functools import cache

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        # 1. Edge Case: If one array is all negative and the other all positive,
        # the recursion would return 0 (empty), but we MUST pick at least one pair.
        # Your check here handles this perfectly.
        if max(nums1) < 0 and min(nums2) > 0:
            return max(nums1) * min(nums2)
        if max(nums2) < 0 and min(nums1) > 0:
            return max(nums2) * min(nums1)
            
        # 2. Add @cache to memorize states
        @cache
        def dfs(i, j):
            # Base case: if we run out of numbers, result is 0
            if i == len(nums1) or j == len(nums2):
                return 0
            
            # 3. The Recursive Choices
            # Option A: Multiply current numbers + Max of the rest
            use_both = nums1[i] * nums2[j] + dfs(i + 1, j + 1)
            
            # Option B: Skip nums1[i]
            skip_one = dfs(i + 1, j)
            
            # Option C: Skip nums2[j]
            skip_two = dfs(i, j + 1)
            
            return max(use_both, skip_one, skip_two)
            
        return dfs(0, 0)
