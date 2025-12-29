class Solution:
    def findMin(self, nums: List[int]) -> int:
        res = float("infinity")
        l, h = 0, len(nums) - 1
        while l < h:
            mid = (l + h) // 2
            if nums[h] < nums[mid]:
                l = mid + 1
            else:
                h = mid

            
        return nums[l]
