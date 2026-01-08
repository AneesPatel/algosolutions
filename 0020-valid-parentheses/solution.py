class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        para = {"{":"}", "[":"]", "(":")"}
        for x in s:
            if x in para:
                stack.append(x)
            else:
                if not stack:
                    return False
                temp = stack.pop()
                if para[temp] != x:
                    return False
        if not stack:
            return True
        else:
            return False
