class Solution(object):
    def groupAnagrams(self, strs):
        if len(strs) == 0:
            return [[""]]
        groupings = {}
        for x in strs:
            newx = ''.join(sorted(x))
            if newx in groupings:
                groupings[newx].append(x)
            else:
                groupings[newx] = [x]
                
        return groupings.values()

