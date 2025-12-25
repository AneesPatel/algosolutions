class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {")": "(", "}": "{", "]": "["}
        
        for x in s:
            if x in mapping:
                top = stack.pop() if stack else '#'
                if mapping[x] != top:
                    return False
            else:
                stack.append(x)
        return not stack
