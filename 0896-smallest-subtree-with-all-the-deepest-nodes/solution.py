class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def depth(node):
            if not node:
                return 0
            return 1 + max(depth(node.left), depth(node.right))
        deepest = depth(root)
        def dfs(node, d):
            if node:
                if d == deepest:
                    return node
                d += 1
                l, r = dfs(node.left, d), dfs(node.right, d)
                if l and r:
                    return node
                return l or r
        return dfs(root, 1)
