class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numsdict = {}
        for index, val in enumerate(nums):
            if target - val in numsdict:
                return([index, numsdict[target-val]])
            else:
                numsdict[val] = index
            
