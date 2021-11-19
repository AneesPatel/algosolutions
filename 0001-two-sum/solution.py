class Solution(object):
    def twoSum(self, nums, target):
        dict = {}
  
        for x in range(len(nums)):
            if target - nums[x] in dict:
                solution = [dict[target - nums[x]],x]
                return solution
            else:
                dict[nums[x]] = x
  
        
