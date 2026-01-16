"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional

class Solution:
    def __init__(self):
        # Initialize the map here so it is accessible across recursive calls
        self.visited = {}

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
            
        # 1. Check if the node is already in our visited map
        if node in self.visited:
            return self.visited[node]
        
        # 2. Create the new node
        # We instantiate the class directly rather than using a 'createNode' function
        new_node = Node(node.val, [])
        
        # 3. Add to map immediately to handle cycles
        self.visited[node] = new_node
        
        # 4. Recursively clone neighbors
        if node.neighbors:
            for neighbor in node.neighbors:
                # Python lists use .append(), not .add()
                new_node.neighbors.append(self.cloneGraph(neighbor))
                
        return new_node
