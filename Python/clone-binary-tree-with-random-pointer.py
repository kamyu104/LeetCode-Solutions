# Time:  O(n)
# Space: O(h)

# Definition for Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, random=None):
        self.val = val
        self.left = left
        self.right = right
        self.random = random


# Definition for NodeCopy.
class NodeCopy(object):
    def __init__(self, val=0, left=None, right=None, random=None):
        pass


class Solution(object):
    def copyRandomBinaryTree(self, root):
        """
        :type root: Node
        :rtype: NodeCopy
        """
        def iter_dfs(node, callback):
            result = None
            stk = [node]
            while stk:
                node = stk.pop()
                if not node:
                    continue
                left_node, copy = callback(node)
                if not result:
                    result = copy
                stk.append(node.right)
                stk.append(left_node)
            return result
    
        def merge(node):
            copy = NodeCopy(node.val)
            node.left, copy.left = copy, node.left
            return copy.left, copy
        
        def clone(node):
            copy = node.left
            node.left.random = node.random.left if node.random else None
            node.left.right = node.right.left if node.right else None
            return copy.left, copy
        
        def split(node):
            copy = node.left
            node.left, copy.left = copy.left, copy.left.left if copy.left else None
            return node.left, copy
    
        iter_dfs(root, merge)
        iter_dfs(root, clone)
        return iter_dfs(root, split)


# Time:  O(n)
# Space: O(h)
class Solution_Recu(object):
    def copyRandomBinaryTree(self, root):
        """
        :type root: Node
        :rtype: NodeCopy
        """
        def dfs(node, callback):
            if not node:
                return None
            left_node, copy = callback(node)
            dfs(left_node, callback)
            dfs(node.right, callback) 
            return copy
    
        def merge(node):
            copy = NodeCopy(node.val)
            node.left, copy.left = copy, node.left
            return copy.left, copy
        
        def clone(node):
            copy = node.left
            node.left.random = node.random.left if node.random else None
            node.left.right = node.right.left if node.right else None
            return copy.left, copy
        
        def split(node):
            copy = node.left
            node.left, copy.left = copy.left, copy.left.left if copy.left else None
            return node.left, copy
    
        dfs(root, merge)
        dfs(root, clone)
        return dfs(root, split)


# Time:  O(n)
# Space: O(n)
import collections


class Solution2(object):
    def copyRandomBinaryTree(self, root):
        """
        :type root: Node
        :rtype: NodeCopy
        """ 
        lookup = collections.defaultdict(lambda: NodeCopy())
        lookup[None] = None
        stk = [root]
        while stk:
            node = stk.pop()
            if not node:
                continue
            lookup[node].val = node.val
            lookup[node].left = lookup[node.left]
            lookup[node].right = lookup[node.right]
            lookup[node].random = lookup[node.random]
            stk.append(node.right)
            stk.append(node.left)
        return lookup[root]


# Time:  O(n)
# Space: O(n)
import collections


class Solution2_Recu(object):
    def copyRandomBinaryTree(self, root):
        """
        :type root: Node
        :rtype: NodeCopy
        """ 
        def dfs(node, lookup):
            if not node:
                return
            lookup[node].val = node.val
            lookup[node].left = lookup[node.left]
            lookup[node].right = lookup[node.right]
            lookup[node].random = lookup[node.random]
            dfs(node.left, lookup)
            dfs(node.right, lookup)
    
        lookup = collections.defaultdict(lambda: NodeCopy())
        lookup[None] = None
        dfs(root, lookup)
        return lookup[root]
