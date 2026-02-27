class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            curval = nums[i]
            for j in range(i + 1, len(nums)):
                curval2 = nums[j]
                if(curval + curval2 == target):
                    return ([i, j])
        
