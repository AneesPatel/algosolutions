class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        nums = {}
        for x in strs:
            key = tuple(sorted(x))
            if key in nums:
                nums[key].append(x)
            else:
                nums[key] = [x]
        
        return list(nums.values())
