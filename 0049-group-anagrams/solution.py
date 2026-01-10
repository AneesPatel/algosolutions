class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        count = {}
        for x in strs:
            sortedx = "".join(sorted(x))
            if sortedx in count:
                count[sortedx].append(x)
            else:
                count[sortedx] = [x]
        
        return list(count.values())
