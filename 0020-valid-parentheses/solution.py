class Solution(object):
    def isValid(self, s):
        paren = {"]": "[", ")": "(", "}": "{"}
        stack = []
        for x in s:
            if x not in paren:
                stack.append(x)
                continue
            if not stack or stack[-1] != paren[x]:
                return False
            stack.pop()

        return not stack
