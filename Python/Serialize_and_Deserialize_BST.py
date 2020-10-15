# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        
        #   Need to construct the string in such a way that
        #   string gets added from left to right, by left
        #   Iterative BFS on tree
        
        #   Queue algorithm (if root is null, return "" before all this)
        #   BFS but for trees
        #   1.  enqueue the root
        #   2.  While queue not empty
        #       a.  dequeue front
        #       b.  convertv value to string and append to string to be returned
        #       c.  If node.left is not null, enqueue to the back
        #       d.  If node.right is not null, enqueue to the back
        #   3.  Return
        
        if not root:
            return ""
        
        from collections import deque
        
        answer = ""
        queue = deque([])
        queue.append(root)
        
        while queue:
            node = queue.popleft()
            answer += str(node.val) + ' '   #   ' ' is the delimiter
            
            if node.left:
                queue.append(node.left)
                
            if node.right:
                queue.append(node.right)

        #   we don't want delimiter at the end of the string
        return answer[:-1]

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        
        #   Basically run insert into a binary tree
        if not data:
            return None
        
        #   split data into a list of strings
        data = data.split(" ")
        root = TreeNode(int(data[0]))
        
        def insert(node, value):
            
            if not node:
                return TreeNode(value)
            
            if node.val <= value:
                node.right = insert(node.right, value)
            else:
                node.left = insert(node.left, value)
                
            return node
        
        #   for each string, run insert
        for i in range(1, len(data)):
            root = insert(root,int(data[i]))

        return root
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
