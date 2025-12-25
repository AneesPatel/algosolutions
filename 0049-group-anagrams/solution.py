class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        counts = {}
        for x in strs:
            sort = "".join(sorted(x))
            if sort in counts:
                counts[sort].append(x)
            else:
                counts[sort] = [x]
        
        return list(counts.values())

            

