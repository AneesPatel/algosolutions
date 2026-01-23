class LL:
    def __init__(self, val, prev = None, nex = None, idx = None):
        self.val = val
        self.prev = prev
        self.nex = nex
        self.idx = idx
        
        

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        from sortedcontainers import SortedList
        
        corruption = 0
        
        
        basis = SortedList(key = lambda x: (x[0].val + x[1].val, x[0].idx))
        
        root = LL(nums[0])
        
        root.idx = 0
        RUT = root
        for i in range(1, len(nums)):
            root.nex = LL(nums[i], root)
            root.nex.idx = i
            root = root.nex
            if nums[i] < nums[i - 1]:
                corruption += 1
            basis.add((root.prev, root))
            
        ans = 0
        while corruption > 0 and len(basis) > 0:
            
#             print(corruption)
#             save_rut = RUT
            
#             print([(i[0].val, i[1].val) for i in basis])
#             while RUT:
#                 print(RUT.val, end = ' ')
#                 RUT = RUT.nex
#             print()
            # RUT = save_rut
            nu = basis.pop(0)
            
            savings = 0
            
            pre = 0
            if nu[0].prev and nu[0].prev.val > nu[0].val:
                pre += 1
            if nu[0].val > nu[1].val:
                pre += 1
            if nu[1].nex and nu[1].nex.val < nu[1].val:
                pre += 1
                
                
            if nu[1].nex and (nu[1], nu[1].nex) in basis:
                basis.remove((nu[1], nu[1].nex))
            if nu[0].prev and (nu[0].prev, nu[0]) in basis:
                basis.remove((nu[0].prev, nu[0]))
            nu[1].val += nu[0].val
            nu[1].prev = nu[0].prev
            
            if nu[0].prev:
                nu[0].prev.nex = nu[1]
            else:
                RUT = nu[1]
            if (nu[1].prev):
                basis.add((nu[1].prev, nu[1]))
            if nu[1].nex:
                basis.add((nu[1], nu[1].nex))
            post = 0
            if nu[1].prev and nu[1].prev.val > nu[1].val:
                post += 1
           
            if nu[1].nex and nu[1].nex.val < nu[1].val:
                post += 1
            savings = pre - post
            
            # print('CORRUT', corruption, savings)
            corruption -= savings
            
            
            ans += 1
        # save_rut = RUT
        # while RUT:
        #     print(RUT.val, end = ' ')
        #     RUT = RUT.nex
        # RUT = save_rut
        
        
        return ans
    
            
        
        
                
                
            
            
