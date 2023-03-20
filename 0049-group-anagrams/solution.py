class Solution(object):
    def groupAnagrams(self, strs):
        groupings = {}
        for str in strs:
            key = "".join(sorted(str))
            if key in groupings:
                groupings.get(key).append( str )
            else:
                groupings[key] = [str]
        print(groupings.values())
        return(groupings.values())
        
