"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        olddict = {}
        def dfs(node):
            if node in olddict:
                return olddict[node]
            clone = Node(node.val)
            olddict[node] = clone
            for cur in node.neighbors:
                clone.neighbors.append(dfs(cur))
            return clone
        if not node:
            return None
        return dfs(node)
         
