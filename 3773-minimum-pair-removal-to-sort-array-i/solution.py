class Solution:
    def minimumPairRemoval(self, nums: List[int], ans = 0) -> int:

        def notSorted(nums: List[int]) -> bool:
            for a, b in pairwise(nums):
                if a > b: return True
            return False

        
        while notSorted(nums):
            minSum, mnIdx = inf, -1
            
            for i, pair in enumerate(pairwise(nums)):
                if sum(pair) < minSum:
                    minSum, mnIdx, delIdx = sum(pair), i, i+1
            
            nums[mnIdx] = minSum
            del nums[delIdx]
            ans+= 1
            
        return ans 
