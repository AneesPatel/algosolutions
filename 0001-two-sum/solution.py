class Solution(object):
    def twoSum(self, nums, target):
        dict = {}
        for indx, val in enumerate(nums):
            if target - val in dict:
                return([dict[target - val], indx])
            dict[val] = indx

       
