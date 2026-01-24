class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1: return nums[0]
        def useArray(arr):
            @cache
            def checkHouse(index):
                if index >= len(arr):
                    return 0
                return max(arr[index] + checkHouse(index + 2), checkHouse(index + 1))
            return checkHouse(0)
        return max(useArray(nums[1:]), useArray(nums[:-1]))
