class Solution(object):
    def twoSum(self, numbers, target):
        p1, p2 = 0, len(numbers) - 1
        while p1 < p2:
            csum = numbers[p1] + numbers[p2]
            if csum > target:
                p2 -= 1
            elif csum < target:
                p1 += 1
            else:
                return [p1 + 1, p2 + 1]
