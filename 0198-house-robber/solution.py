class Solution:
    def rob(self, nums: List[int]) -> int:
        @cache
        def checkHouse(index):
            if index >= len(nums):
                return 0
            return max(checkHouse(index + 1), checkHouse(index+2) + nums[index])
        return checkHouse(0)
