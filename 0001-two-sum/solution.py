class Solution(object):
    def twoSum(self, nums, target):
        map = {}
        for i, x in enumerate(nums):
            diff = target - x
            if diff in map:
                return (map[diff], i)
            map[x] = i
        return

