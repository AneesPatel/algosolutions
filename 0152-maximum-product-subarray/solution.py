class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        self.global_max = float('-inf')
        @cache
        def findMinMax(index):
            if index == len(nums) - 1:
                self.global_max = max(self.global_max, nums[index])
                return nums[index], nums[index]
            nextMin, nextMax = findMinMax(index + 1)
            cur = nums[index]
            
            curMin = min(cur, cur*nextMin, cur*nextMax)
            curMax = max(cur, cur*nextMin, cur*nextMax)
            self.global_max = max(self.global_max, curMax)
            return curMin, curMax
        findMinMax(0)
        return self.global_max
