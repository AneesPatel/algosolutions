class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrack(index, templist):
            res.append(templist[:])
                
            
            for x in range(index, len(nums)):
                templist.append(nums[x])
                backtrack(x + 1, templist)
                templist.pop()
        backtrack(0,[])
        return res

