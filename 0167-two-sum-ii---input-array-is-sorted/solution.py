class Solution(object):
    def twoSum(self, numbers, target):
        p1 = 0
        p2 = len(numbers) - 1
        print(numbers[p1], numbers[p2])
        while p1 < p2:
            tsum = numbers[p1] + numbers[p2]
            if tsum > target:
                p2 -= 1
            elif tsum < target:
                p1 += 1
            else:
                return [p1 + 1, p2 + 1]

            
        
