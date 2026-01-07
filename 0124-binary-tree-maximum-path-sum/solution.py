# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = float("-inf")
        self.dfs(root)
        return self.res
    def dfs(self, root):
        if not root:
            return False
        
        leftmax = max(self.dfs(root.left), 0)
        rightmax = max(self.dfs(root.right), 0)
        self.res = max(self.res, leftmax + rightmax + root.val)
        
        return root.val + max(leftmax, rightmax)
